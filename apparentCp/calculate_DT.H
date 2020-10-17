Info<< "calculating DT_mean" << endl;

forAll(mesh.C(),i)
{
  DT[i] = k.value()/rho.value()/cp_app[i];
}

forAll(mesh.boundary(),patchID)
{
  DT[patchID] = k.value()/rho.value()/cp_app[patchID];

forAll (mesh.boundary()[patchID],facei)
    {
      DT.boundaryFieldRef()[patchID][facei] = k.value()/rho.value()/cp_app.boundaryField()[patchID][facei];
    }
}
