#!/bin/bash

set -x

rm -rf /opt/openfoam7/applications/solvers/apparentCp/

cp -r /home/davide/OpenFOAM/davide-7/openfoam7/applications/solvers/melting/conduction/apparentCp /opt/openfoam7/applications/solvers/

wmake /opt/openfoam7/applications/solvers/apparentCp
