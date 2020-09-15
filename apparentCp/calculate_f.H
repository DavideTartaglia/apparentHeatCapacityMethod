forAll(mesh.C(),i)
{
  // f[i] = std::min(1,std::max(0,((T[i]-Tm.value())/r.value())));
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


forAll(mesh.boundary(),i)
{
  // f[i] = std::min(1,std::max(0,((T[i]-Tm.value())/r.value())));
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
