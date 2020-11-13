Info<< "calculating cp_mean" << endl;

/*
volScalarField cp_mean_new = cp_s - f*(cp_s - cp_l);
cp_mean = cp_mean_new;
*/

forAll(mesh.C(),i)
{
  cp_mean[i]=cp_s.value()-f[i]*(cp_s.value()-cp_l.value());
}

forAll(mesh.boundary(),patchID)
{
  cp_mean[patchID]=cp_s.value()-f[patchID]*(cp_s.value()-cp_l.value());

  forAll (mesh.boundary()[patchID],facei)
    {
      cp_mean.boundaryFieldRef()[patchID][facei] = cp_s.value() - f.boundaryField()[patchID][facei]*(cp_s.value()-cp_l.value());
    }
}

Info<< "calculating cp_app" << endl;

forAll(mesh.C(),i)
{
  if (f[i]==0)
    {
      cp_app[i] = cp_s.value();
    }
  else if (f[i]>0 && f[i]<1)
    {
      cp_app[i] = cp_mean[i] + L.value()/(Tl.value() - Ts.value());
    }
  else if (f[i]==1)
    {
      cp_app[i] = cp_l.value();
    }
}


forAll(mesh.boundary(),patchID)
{
  if (f[patchID]==0)
    {
      cp_app[patchID] = cp_s.value();
    }
  else if (f[patchID]>0 && f[patchID]<1)
    {
      cp_app[patchID] = cp_mean[patchID] + L.value()/(Tl.value() - Ts.value());
    }
  else if (f[patchID]==1)
    {
      cp_app[patchID] = cp_l.value();
    }

  forAll (mesh.boundary()[patchID],facei)
    {
  if (f.boundaryField()[patchID][facei]==0)
    {
      cp_app.boundaryFieldRef()[patchID][facei] = cp_s.value();
    }
  else if (f.boundaryField()[patchID][facei]>0 && f.boundaryField()[patchID][facei]<1)
    {
      cp_app.boundaryFieldRef()[patchID][facei] = cp_mean.boundaryField()[patchID][facei] + L.value()/(Tl.value() - Ts.value());
    }
  else if (f.boundaryField()[patchID][facei]==1)
    {
      cp_app.boundaryFieldRef()[patchID][facei] = cp_l.value();
    }
    }
}
