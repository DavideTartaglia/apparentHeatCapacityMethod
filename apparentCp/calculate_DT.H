forAll(mesh.C(),i)
{
  DT[i] = k.value()/rho.value()/cp_app[i];
}

forAll(mesh.boundary(),i)
{
  DT[i] = k.value()/rho.value()/cp_app[i];
}
