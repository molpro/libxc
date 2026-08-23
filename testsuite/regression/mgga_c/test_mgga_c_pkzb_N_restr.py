
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_pkzb_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pkzb", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.451855418499447e-02, -6.369908204618208e-02, -6.251731773036086e-02, -6.081044249413588e-02, -5.833878503032921e-02, -5.474510448095033e-02, -4.949195397152815e-02, -4.180107907286806e-02, -3.089701636858136e-02, -1.812084626726702e-02, -1.228344261642062e-02, -4.306028170292077e-02, -5.231851590800820e-02, -3.712801196399593e-02, -2.132616212186438e-02, -6.323600233554766e-03, -4.678438164214659e-04, -5.326644612223991e-06, -5.289922619036383e-09, -1.642378010660589e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_pkzb_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pkzb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.152335178211464e-01, -1.143050980390332e-01, -1.129858064267819e-01, -1.111220041885419e-01, -1.085115772985355e-01, -1.048982324784731e-01, -9.994825717841757e-02, -9.302536618004167e-02, -8.192474788316424e-02, -6.181881268714112e-02, -4.866530496284376e-02, -8.840953015899973e-02, -8.222368365517385e-02, -7.459663139885368e-02, -5.815510694288127e-02, -2.641478338491578e-02, -2.558279212222654e-03, -3.162083994267236e-05, -3.234145455162327e-08, -1.025669197932763e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pkzb_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pkzb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.159421056818668e-07, 5.402594073149164e-07, 5.775050027091957e-07, 6.362750647992546e-07, 7.333576192063578e-07, 9.058616383947411e-07, 1.251066338628151e-06, 2.082766216134256e-06, 4.604213391493580e-06, 1.384651418184751e-05, 8.832205515694490e-05, 3.434692956507708e-03, 9.591158671949523e-03, 1.240616555396925e-02, 2.744047917210976e-02, 8.676979420244584e-02, 1.172268283138627e-01, 4.873066050433751e-02, 6.035365472897255e-03, 1.504918029989512e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pkzb_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pkzb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.839338512364613e-05, 4.667195313589301e-05, 7.242251894961778e-05, 1.082715433974975e-04, 1.571274934100829e-04, 2.209457978781993e-04, 2.965902139707553e-04, 3.642807634773309e-04, 3.677518331350127e-04, 2.457768320214968e-04, 1.049993810321557e-04, 4.006450095965720e-06, -2.505907524846182e-04, 8.741335905793820e-04, 4.156089149940700e-03, 2.548049900102702e-03, 2.630931033075678e-04, 3.522905925975125e-06, 3.622242282354677e-09, 1.053437666425146e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pkzb_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pkzb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.673371520048561e-04, -4.949087378949877e-04, -5.368198532693367e-04, -6.019830468429726e-04, -7.065525592861841e-04, -8.823864955765434e-04, -1.203933983294206e-03, -1.926041184589777e-03, -4.471443180148468e-03, -1.674943603399402e-02, -6.543583910980273e-02, -2.576745678080593e-02, 5.331017508162408e-03, -9.874920677863580e-02, -6.731430103700549e-01, -5.669838452752843e+00, -1.140496967253900e+01, -4.935467893772112e+00, -5.906458430770808e-01, -1.418369549140163e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pkzb_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pkzb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.123750159057687e-09, 9.173239241083906e-09, 1.090839514233816e-08, 1.395000877775386e-08, 1.973359918249366e-08, 3.202848827130164e-08, 6.246920434389474e-08, 1.571936541754179e-07, 6.286759978688250e-07, 6.202512557067976e-06, 1.665428206725158e-04, 1.093217338540802e-03, -9.819639891378453e-03, 4.886487879122141e-02, 6.638137402270946e-01, 2.640153697673296e+01, 6.757452292738411e+02, 9.627168732881528e+03, 1.380420416224604e+05, 2.578577325637463e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_pkzb_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pkzb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.712119604605949e-06, -8.192393399551605e-06, -8.919905385797074e-06, -1.004070934441188e-05, -1.179623310235205e-05, -1.455513464072760e-05, -1.864393965744528e-05, -2.277181620617276e-05, -1.616493844133844e-05, 3.171259752067889e-05, 8.456878143973500e-05, -1.320906336153858e-04, -1.409230466587169e-03, -4.125777334050747e-02, -6.552419188781455e-02, 4.372370435596206e-01, 1.022935874715227e+00, 4.814337513595033e-01, 5.790989192989872e-02, 1.266001360428058e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pkzb_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pkzb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.774750666929918e-13, -2.151503068271065e-13, -2.834031777712684e-13, -4.200096668308208e-13, -7.350265628320662e-13, -1.622294273981999e-12, -4.930006631449958e-12, -2.322035327628088e-11, -2.051934952259200e-10, -4.972819241816333e-09, -7.303127522086948e-07, -7.752747426975708e-04, -8.464165559655351e-03, -6.509043500165104e-02, -1.709326647192578e+00, -2.274095577942691e+02, -5.983148750461012e+04, -2.704148510930784e+07, -4.600324129272150e+10, -6.593245916959285e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_pkzb_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pkzb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.183066636167529e-11, 1.092836499304702e-10, 1.393920501289836e-10, 1.953289922943517e-10, 3.103077610279774e-10, 5.806160235179986e-10, 1.333853261402827e-09, 3.882529423258668e-09, 1.411686270908309e-08, 6.009302490665848e-08, 5.298897562252307e-07, 1.327129820007384e-05, -4.458744280934625e-04, 2.259694566990116e-02, 3.213132686769095e-01, 2.787713374328565e+00, 1.034339798614685e+01, 1.787716255954085e+01, 1.452059781376169e+01, 4.009815806904309e+00]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_pkzb_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pkzb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.934953745188704e-08, -3.386857399060339e-08, -5.752231351452521e-08, -9.790700705772200e-08, -1.711476732812242e-07, -3.141223862279968e-07, -6.166329027732697e-07, -1.299107289071314e-06, -2.808461033049535e-06, -5.458970402261499e-06, -1.027323501953902e-05, -2.817884758465321e-06, 1.213578897205989e-03, -1.196001454728896e-02, -1.924463409939990e-01, -7.469120851020338e-01, -1.032457935007704e+00, -4.771759093614218e-01, -6.096212722190659e-02, -1.400736841139286e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
