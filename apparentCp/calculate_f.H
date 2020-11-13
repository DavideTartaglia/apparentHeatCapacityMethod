/*
volScalarField fnew = min( scalar(1), max(scalar(0), (T-Ts)/(Tl-Ts) ) );
f = fnew ;
*/

forAll(mesh.C(),i)
{
  // f[i] = std::min(1,std::max(0,( (T[i] - Ts.value()) / (Tl.value() - Ts.value()) ) ));
  if (T[i]<Ts.value())
    {
      f[i] = 0;
    }
  else if (T[i]>Tl.value())
    {
      f[i] = 1;
    }
  else if (T[i]>=Ts.value() && T[i]<=Tl.value())
    {
      f[i] = (T[i]-Ts.value())/(Tl.value()-Ts.value());
    }
    
}


forAll(mesh.boundary(),patchID)
{
  // f[i] = std::min(1,std::max(0,((T[i]-Tm.value())/r.value())));
  if (T[patchID]<Ts.value())
    {
      f[patchID] = 0;
    }
  else if (T[patchID]>Tl.value())
    {
      f[patchID] = 1;
    }
  else if (T[patchID]>=Ts.value() && T[patchID]<=Tl.value())
    {
      f[patchID] = (T[patchID]-Ts.value())/(Tl.value()-Ts.value());
    }

  forAll (mesh.boundary()[patchID],facei)
    {
      if (T.boundaryField()[patchID][facei]<Ts.value())
	{
	  f.boundaryFieldRef()[patchID][facei] = 0;
	}
      else if (T.boundaryField()[patchID][facei]>Tl.value())
	{
	  f.boundaryFieldRef()[patchID][facei] = 1;
	}
      else if (T.boundaryField()[patchID][facei]>=Ts.value() && T.boundaryField()[patchID][facei]<=Tl.value())
	{
	  f.boundaryFieldRef()[patchID][facei] = (T.boundaryField()[patchID][facei]-Ts.value())/(Tl.value()-Ts.value());
	}
    }
    
}
