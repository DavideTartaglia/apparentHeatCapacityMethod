/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2018 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    apparentCp

Description
    Solves the apparent cp method.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "fvOptions.H"
#include "pimpleControl.H"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "setRootCaseLists.H"

    #include "createTime.H"
    #include "createMesh.H"

    pimpleControl pimple(mesh);

    #include "createFields.H"

    Info<< "\nStarting time loop\n" << endl;

    while (runTime.run())
    {

      runTime++;
      Info<< "\nTime = " << runTime.timeName() << nl << endl;
 
      // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
      	  
      // there's the need to inizialize the surface BC on the patch walls:
      #include "inizializeBC.H"
      
      while (pimple.loop())
	{
	  
	  Info<< "\nCalculating temperature distribution\n" << endl;

	  fvScalarMatrix TEqn
		    (
		     fvm::ddt(T) - DT*fvm::laplacian(T)
		     ==
		     fvOptions(T)
		     );

		  fvOptions.constrain(TEqn);
		  TEqn.solve();
		  fvOptions.correct(T);
	  
	  
          #include "calculate_f.H"

          #include "calculate_cp.H"

          #include "calculate_DT.H"

		  Info<< endl;
		  Info<< endl;
	  
	}
      
      #include "write.H"

      Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
	  << "  ClockTime = " << runTime.elapsedClockTime() << " s"
	  << nl << endl;

    }

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
