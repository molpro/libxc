
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_k_zlp_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_zlp", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.575233671047935e+02, 1.513493474425170e+02, 1.428970037926413e+02, 1.315732313442803e+02, 1.168659261215852e+02, 9.859327014756234e+01, 7.728318942588484e+01, 5.456948014428814e+01, 3.327301312256130e+01, 1.671510747137419e+01, 7.253778209511040e+00, 4.345909488339392e+00, 3.370431358282339e+00, 2.162002846502997e+00, 1.018011444275270e+00, 3.321212775697494e-01, 6.864021141956263e-02, 7.633813082159789e-03, 3.478560304991966e-04, 4.361213974059626e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_k_zlp_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_zlp", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.603873540841120e+02, 2.603830932415071e+02, 2.502159882544430e+02, 2.502072520033516e+02, 2.362897436738644e+02, 2.362718998429238e+02, 2.176300260707320e+02, 2.175937741184055e+02, 1.933912530658883e+02, 1.933181387504863e+02, 1.632730067616276e+02, 1.631269725510940e+02, 1.281500400433784e+02, 1.278619436165684e+02, 9.073627887845460e+01, 9.017622851019490e+01, 5.573677487732157e+01, 5.466565584226713e+01, 2.871381875166151e+01, 2.670745315239549e+01, 1.342544906495025e+01, 9.912970818505949e+00, 8.292383012629463e+00, 3.759026192756299e+00, 6.410144633338484e+00, 2.727763519402862e+00, 4.120507182229734e+00, 1.811476038905737e+00, 1.933411845145744e+00, 7.985366093603854e-01, 6.228002907764058e-01, 2.182806534018801e-01, 1.252513911943655e-01, 3.264036847254066e-02, 1.339614701046535e-02, 2.135930814947906e-03, 5.906632073524474e-04, 4.405908913653458e-05, 7.299072456737498e-06, 1.929113757938135e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_k_zlp_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_zlp", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.923684632973668e+00, -3.095796892490279e-02, 1.923701144942178e+00, 1.965449401486017e+00, -3.113901445805000e-02, 1.965485372388917e+00, 2.026980082262135e+00, -3.139927988227403e-02, 2.027060238828707e+00, 2.118574265269076e+00, -3.177330096215932e-02, 2.118758812391653e+00, 2.256947787770351e+00, -3.231050526715437e-02, 2.257393179146447e+00, 2.470422025046438e+00, -3.308143238071060e-02, 2.471572711975453e+00, 2.809648923603294e+00, -3.418630119277690e-02, 2.812929850614924e+00, 3.371236794789486e+00, -3.576617642185568e-02, 3.382027417402411e+00, 4.351163014441451e+00, -3.801238347102308e-02, 4.394714037313425e+00, 6.138586002427734e+00, -4.111560111801994e-02, 6.369604884087978e+00, 9.076111121355968e+00, -4.439110061858872e-02, 1.058431655867066e+01, 1.161090014526904e+01, -4.372866192865878e-02, 1.730507800295652e+01, 1.323702680337017e+01, -4.427507425576938e-02, 2.035739832939305e+01, 1.656727329408373e+01, -4.638164200612375e-02, 2.505277589464443e+01, 2.429860672659066e+01, -4.892769995737618e-02, 3.788399950483236e+01, 4.301405265705667e+01, -5.179397410395172e-02, 7.275006818179079e+01, 9.627665955922194e+01, -5.454895924135410e-02, 1.887142623587685e+02, 2.950720107721178e+02, -5.695577480561451e-02, 7.390725211208234e+02, 1.406680376829595e+03, -6.051206355378706e-02, 5.150203559907296e+03, 1.265777133199374e+04, -6.859700475124839e-02, 7.785565423246031e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
