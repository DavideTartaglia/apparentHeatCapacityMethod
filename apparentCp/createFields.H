Info<< "Reading transportProperties\n" << endl;

IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

Info<< "Reading desity rho\n" << endl;

dimensionedScalar rho
(
    transportProperties.lookup("rho")
);


Info<< "Reading thermal conductivity k\n" << endl;

dimensionedScalar k
(
    transportProperties.lookup("k")
);


Info<< "Reading liquid thermal capacity cp_l\n" << endl;

dimensionedScalar cp_l
(
    transportProperties.lookup("cp_l")
);


Info<< "Reading solid thermal capacity cp_s\n" << endl;

dimensionedScalar cp_s
(
    transportProperties.lookup("cp_s")
);


Info<< "Reading specific enthalpy of melting L\n" << endl;

dimensionedScalar L
(
    transportProperties.lookup("L")
);


Info<< "Reading solidus temperature Ts\n" << endl;

dimensionedScalar Ts
(
    transportProperties.lookup("Ts")
);


Info<< "Reading liquidus temperature Tl\n" << endl;

dimensionedScalar Tl
(
    transportProperties.lookup("Tl")
);



#include "createFvOptions.H"


Info<< "Reading field T\n" << endl;

volScalarField T
(
    IOobject
    (
        "T",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Reading field f\n" << endl;

volScalarField f
(
    IOobject
    (
        "f",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("boh",dimless,pTraits<scalar>::zero)
 );


Info<< "Reading field mean cp (cp_mean)\n" << endl;

volScalarField cp_mean
(
    IOobject
    (
        "cp_mean",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    cp_s
 );


Info<< "Reading field apparent cp (cp_app)\n" << endl;

volScalarField cp_app
(
    IOobject
    (
        "cp_app",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    cp_s
 );


Info<< "Reading field effective diffusivity DT\n" << endl;

volScalarField DT
(
    IOobject
    (
        "DT",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    k/rho/cp_s
 );
