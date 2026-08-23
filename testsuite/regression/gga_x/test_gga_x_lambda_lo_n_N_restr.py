
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_lambda_lo_n_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_lo_n", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.303465966025387e+00, -4.221751669232966e+00, -4.107360264183270e+00, -3.949130511618536e+00, -3.734007361594112e+00, -3.448713108847026e+00, -3.083623559030872e+00, -2.639582734729824e+00, -2.136059834602305e+00, -1.609607985513004e+00, -1.082703259324316e+00, -6.644482148851892e-01, -5.627473842863749e-01, -4.720757440539374e-01, -3.492486804096114e-01, -2.286376497813807e-01, -1.207873796160608e-01, -4.187858870741662e-02, -8.769836682071775e-03, -9.702054254300053e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_lambda_lo_n_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_lo_n", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.379090879187058e+00, -5.264668353208569e+00, -5.104249389450237e+00, -4.881864036544174e+00, -4.578535687880682e+00, -4.174367268940403e+00, -3.653839135372310e+00, -3.016692402230280e+00, -2.298380244327834e+00, -1.600209599055624e+00, -1.044777851992908e+00, -7.992721308640186e-01, -7.153007668740217e-01, -5.548820278906732e-01, -3.610982186962837e-01, -2.158461250743471e-01, -1.361104338364779e-01, -5.452864511291343e-02, -1.167999564427569e-02, -1.293588570869045e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lambda_lo_n_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_lo_n", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.850539040645603e-06, -4.164173366057425e-06, -4.659017432445248e-06, -5.471579360363275e-06, -6.883747351268177e-06, -9.542432162605512e-06, -1.513716022319666e-05, -2.882201130290918e-05, -6.935782725176028e-05, -2.196875903139249e-04, -1.062254014319759e-03, -6.953777175319146e-03, -1.301370729651706e-02, -2.769803492375997e-02, -9.852910718793088e-02, -4.765971239811675e-01, -1.690623962515176e+00, -2.950742458432784e+00, -3.572127362263789e+00, -3.946018168001540e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lambda_lo_n_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_lo_n", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.223541309720568e-02, -1.279914011331090e-02, -1.365497683966518e-02, -1.498463913261258e-02, -1.711844989817644e-02, -2.069771429630726e-02, -2.705094370120953e-02, -3.898921993092817e-02, -6.113067578380409e-02, -8.714512131069278e-02, -1.333682688563274e-01, -5.652873048668573e-01, -6.795313303259611e-01, -1.170910652595242e+00, -2.176776146690560e+00, 2.182491734221950e+00, 2.864480062240517e+01, -4.077924496024663e+02, -1.344791249001967e+04, -1.116664501304763e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lambda_lo_n_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_lo_n", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.385592785237811e-08, 2.721815571636481e-08, 3.286867047857732e-08, 4.301782528512807e-08, 6.303237145838474e-08, 1.079267333954386e-07, 2.272735460201802e-07, 6.129888346092571e-07, 1.946056041830259e-06, -1.345270018037382e-06, -2.221399159208693e-04, 1.084150712366719e-02, 3.701997001757378e-02, 1.132983912139167e-01, 3.582714575656938e-01, -4.478189492386976e+01, -5.073636945384684e+03, -3.536618963059549e+05, -4.994295687630992e+07, -4.088205217696532e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lambda_lo_n_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_lo_n", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.163232232450172e-14, 6.563083997532159e-14, 9.260916206592147e-14, 1.517328160288717e-13, 3.076285412587945e-13, 8.438808603305350e-13, 3.543219505422420e-12, 2.685365126474501e-11, 4.505833231244742e-10, 2.053745895973671e-08, 2.939726637503653e-06, 3.313209431192271e-04, 1.924489347056960e-03, 2.214480247468240e-02, 1.510023065937713e+00, 5.320988128531325e+02, 4.995394641077500e+05, 1.072389446004299e+09, 1.813806517579215e+13, 1.152525429779457e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
