For OpenFOAM users.
Add this folder in the /solver directory of user directory and compile it using wmake. Run it typing "apparentCp" in the case folder.

The Apparent Heat Capacity method, as implemented here, solve PURE CONDUCTION cases for phase change. This version of the solver is only for conduction problems, and both phases are assumed to have zero velocity.

This solver requires to define a certain deltaT between the solidus Ts and the liquidus Tl. Remember to set them accordingly in the transport properties. Checkout the tutorial for further info.
If the phase change is isothermal, you still need to set two different temperatures for the solidus and the liquidus in a ficticious way. Try to set Tl and Ts as close as possible to Tmelting, but still sufficiently further apart to allow convergence. Typical values are about Ts = Tmelt - 0.5K, and Tl = Tmelt + 0.5K

This method doesn't keep track of the differences in the densities between the solid and the liquid phase.

It has been validated in 1D and 3D over analytical solution of the two-phase Stefan problem.
