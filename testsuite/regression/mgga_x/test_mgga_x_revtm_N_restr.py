
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_revtm_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtm", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.654704622835631e+00, -4.562039899584487e+00, -4.432261150047289e+00, -4.252627337960632e+00, -4.008157029128966e+00, -3.683437429365211e+00, -3.266876525538677e+00, -2.758242025924181e+00, -2.177966858304826e+00, -1.568621976995784e+00, -9.974318176261934e-01, -6.575049512079889e-01, -5.583784596771828e-01, -4.754110901723146e-01, -3.427467105388789e-01, -2.093438771639689e-01, -1.087775791467760e-01, -4.828991898083516e-02, -1.774566141512114e-02, -4.666611679874021e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_revtm_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.090607892035034e+00, -5.959667491927797e+00, -5.775950981139645e+00, -5.520980115108570e+00, -5.172612105010553e+00, -4.707220259265478e+00, -4.105411026647481e+00, -3.363913684085540e+00, -2.517554396084709e+00, -1.675427806639189e+00, -1.082634951493955e+00, -8.105967896240436e-01, -7.323974465561532e-01, -5.719088765763062e-01, -3.755185450606497e-01, -2.060183760331737e-01, -9.244329398591047e-02, -3.249711109323675e-02, -9.901119218889254e-03, -2.423414294347880e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtm_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.645158712679428e-06, -1.908163795911081e-06, -2.334177783377611e-06, -3.058870474633836e-06, -4.377907692684104e-06, -7.010470825951506e-06, -1.295445066634037e-05, -2.872224323746360e-05, -7.990306157718120e-05, -2.849753169192256e-04, -8.220335592636343e-04, -3.102091866572105e-03, -1.101405294102446e-02, -5.341368534979423e-02, -1.397295236979678e-01, -6.283617750254913e-01, -5.546660339866091e+00, -1.104097041905776e+02, -5.823579606404133e+03, -1.266769636331884e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtm_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.192622696765038e-04, 1.073216774138114e-03, 1.292877767220660e-03, 1.605353260233327e-03, 2.048112593939769e-03, 2.672143685632639e-03, 3.544718813555852e-03, 4.746552191793470e-03, 6.320299627373412e-03, 7.649077882399512e-03, 1.929046347458986e-03, -2.388639775105245e-03, 6.985128975850617e-03, 4.780803167032352e-02, 4.145636963697261e-02, 3.019250164801314e-02, 2.252862264768475e-02, 1.491623638320886e-02, 7.334797633003045e-03, 2.251162288247090e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtm_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.249620184526910e-03, -5.569074753564311e-03, -6.060814465330662e-03, -6.839385243433071e-03, -8.120590616342856e-03, -1.033906718533284e-02, -1.442756517196976e-02, -2.246695716438673e-02, -3.915319604129709e-02, -8.188157682930845e-02, -2.062300725296064e-01, -4.516228236360200e-01, -7.028331144190857e-01, -1.178448620042213e+00, -1.905728758146858e+00, -6.402182324537538e+00, -7.501629341656729e+01, -1.420266196569335e+03, -5.978387474518993e+04, -1.097720672456973e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtm_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.248027995352702e-07, -2.479153200001456e-07, -2.853154768553873e-07, -3.490253372353445e-07, -4.658557462998823e-07, -7.040423354646804e-07, -1.269858151796107e-06, -2.947144917491295e-06, -9.690441062665703e-06, -3.935193401591732e-05, 2.182092978940827e-04, 6.159492243420686e-03, 8.606419405583774e-03, 6.956280591736594e-02, -1.096934676639216e+00, 1.011278934419749e+01, 8.806997051990244e+03, 7.463157997411934e+06, 4.230249638357280e+10, 6.175968704559057e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtm_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.628232894522257e-04, 3.781345429722005e-04, 4.013002698965804e-04, 4.371164480667539e-04, 4.942108430815017e-04, 5.891947314359192e-04, 7.565948143690635e-04, 1.072685261188090e-03, 1.686854307600395e-03, 2.223986241505208e-03, -3.153936320366596e-03, -5.350185834194578e-03, 3.421895579483156e-02, 5.767901841146831e-02, 7.455450260650367e-01, -9.455478773725127e-01, -6.650122777148866e+01, -1.942819280182757e+03, -1.030048462376351e+05, -2.086811383200124e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtm_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.463396861626323e-12, 8.810288431466429e-12, 1.118389898865228e-11, 1.575800557309375e-11, 2.578546769834101e-11, 5.226335050883377e-11, 1.437247485733599e-10, 6.085905055612522e-10, 4.644517604186257e-09, 6.022096909421091e-08, -3.315582912425107e-06, 2.651630136681313e-04, -1.420998991844014e-02, -5.181270198756782e-02, 3.726798352467527e+00, -9.127538234335253e+01, -1.515435775698096e+06, -4.382884782404238e+10, -3.055338600809473e+16, -3.480505272236680e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtm_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.119204404629692e-08, -1.241515575663911e-08, -1.441053151774548e-08, -1.784886055370711e-08, -2.425492900597621e-08, -3.758927681476470e-08, -7.000367131781831e-08, -1.670576034617741e-07, -5.315820186730254e-07, -1.200385012199007e-06, 5.372272547465408e-05, -2.426842977902694e-04, 2.602919754728762e-02, 2.357366189018530e-01, -4.807305424779091e-02, 5.384945121840865e+01, 1.624698382957559e+04, 1.443943884972425e+07, 9.335189878881059e+10, 1.505201058871243e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtm_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.656248675052240e-05, 1.725979288602834e-05, 1.831153572778069e-05, 1.992846578242369e-05, 2.247867377491154e-05, 2.663294103952488e-05, 3.363786652660150e-05, 4.554283892600303e-05, 6.145675422375245e-05, 8.549389863836432e-06, -5.475404757266725e-04, 8.415913288729966e-04, -4.378578014211202e-02, -4.481770753924645e-01, -5.589061722473023e-01, -6.807982612950089e+00, -1.393668920109569e+02, -4.027759297906943e+03, -2.388300068946526e+05, -5.366215393872017e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
