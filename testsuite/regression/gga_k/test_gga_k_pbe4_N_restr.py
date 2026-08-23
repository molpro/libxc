
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_pbe4_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe4", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.022834703688714e+01, 7.835689971662362e+01, 7.586476811983738e+01, 7.264496746227140e+01, 6.863377332019935e+01, 6.378676766226599e+01, 5.783217261483277e+01, 4.954191325113921e+01, 3.625779996408958e+01, 1.850070255211422e+01, 7.171516946081965e+00, 2.462087537796872e+00, 1.258064075417278e+00, 1.412471452625097e+00, 9.542311208899416e-01, 1.804797659033394e-01, -6.718695721174583e-03, -2.317699512837749e-03, -1.087065705801414e-04, -1.334493791969100e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_pbe4_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.159448750399627e+01, 3.549817690846749e+01, 2.760126191388591e+01, 1.799251337032454e+01, 7.613794276228060e+00, -8.135956991345149e-01, -1.761734123070329e+00, 1.161518722371765e+01, 3.545538779056409e+01, 3.989482402569902e+01, 1.965714680847260e+01, -9.407863300836483e-02, 1.390574248951816e+00, 6.811094238689706e-03, 1.470558808299913e+00, 7.472962730606396e-01, 3.187779305698071e-02, -3.259724983780824e-03, -1.799601525795419e-04, -2.223965087120903e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pbe4_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.884237321441068e-04, 1.086912285349079e-03, 1.237128058236375e-03, 1.470177353500005e-03, 1.836897994965106e-03, 2.411396930231039e-03, 3.246287316942497e-03, 4.067729862039490e-03, 3.151106386560313e-03, -3.645932341329803e-03, -2.052085838644912e-02, 3.368252796120317e-01, 2.623611615552547e-01, 8.720833689563424e-01, 1.129077309934724e-01, -2.390890826440831e+00, -2.920064541099443e+00, -1.359031301789342e+00, -3.314758256181184e-01, -4.043330067904471e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pbe4_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.934904125189857e+00, 1.933874061395413e+00, 1.911875298030571e+00, 1.831003966501192e+00, 1.592267187711215e+00, 9.372101048213577e-01, -7.766317558930437e-01, -4.776695490103202e+00, -1.092004607568048e+01, -9.724267590172568e+00, -4.091854110844273e+00, 2.561764383287465e+00, 1.479097506530342e+01, -9.972987727157486e+00, -6.562292086080178e+01, 9.097679402445178e+01, 1.849971044718081e+02, 1.240236855364947e+01, -4.015935163018177e+02, -3.838105375652536e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pbe4_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.909975358939702e-05, -2.049760141141884e-05, -2.243698706376022e-05, -2.485583362308297e-05, -2.662246075394327e-05, -2.123628268239816e-05, 2.504362208909877e-05, 2.863331239887885e-04, 1.555754560903023e-03, 5.728736283790909e-03, 3.262409724455647e-02, -2.136901799996653e-01, -4.657393751429222e+00, 3.713111504174206e+00, 7.562180383848900e+01, -2.579985448894483e+02, -1.107383629176283e+04, -1.800963120086127e+05, -5.025470219052105e+06, -4.538164620884826e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pbe4_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.457162202034731e-10, 1.605307778365004e-10, 1.804582000349475e-10, 2.002825243278385e-10, 1.794088431619207e-10, -1.423518042124409e-10, -2.607307298465546e-09, -2.297725833466584e-08, -2.200159645810655e-07, -2.056389780524480e-06, -5.287224040470387e-05, -2.649321114706804e-02, 1.493222327926461e+00, -2.896431568773051e+00, -7.284339879587239e+01, 2.481292653203616e+03, 9.522545019778796e+05, 5.009757212108312e+08, 1.684254400630910e+12, 1.180957807238669e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
