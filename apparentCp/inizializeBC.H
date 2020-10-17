// f.boundaryFieldRef()  returns a reference to the boundary field
// T.boundaryField()     returns a const-reference to the boundary field

// f field

forAll(mesh.boundary(), patchID)
{
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


// cp_mean field

forAll(mesh.boundary(), patchID)
{
  forAll (mesh.boundary()[patchID],facei)
    {
      cp_mean.boundaryFieldRef()[patchID][facei] = cp_s.value() - f.boundaryField()[patchID][facei]*(cp_s.value()-cp_l.value());
    }
}


// cp_app field

forAll(mesh.boundary(), patchID)
{
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


// DT field

forAll(mesh.boundary(), patchID)
{
  forAll (mesh.boundary()[patchID],facei)
    {
      DT.boundaryFieldRef()[patchID][facei] = k.value()/rho.value()/cp_app.boundaryField()[patchID][facei];
    }
}
