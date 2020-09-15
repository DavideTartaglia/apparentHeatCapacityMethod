Info<< "calculating cp_mean" << endl;

forAll(mesh.C(),i)
{
  cp_mean[i]=cp_s.value()-f[i]*(cp_s.value()-cp_l.value());
}

forAll(mesh.boundary(),i)
{
  cp_mean[i]=cp_s.value()-f[i]*(cp_s.value()-cp_l.value());
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

forAll(mesh.boundary(),i)
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
