For OpenFOAM users.
Add this folder in the /solver directory and compile it using wmake.

The Apparent Heat Capacity method requires to define a certain deltaT between the solidus Ts and the liquidus Tl. Remember to set them accordingly in the transport properties.
If the phase change is isothermal, you still need to set two different temperatures for the solidus and the liquidus in a ficticious way.

This method doesn't keep track of the differences in the densities between the solid and the liquid phase.
