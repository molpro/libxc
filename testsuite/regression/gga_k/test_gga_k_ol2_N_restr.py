
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_ol2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ol2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.457479601343070e+01, 9.089674864541342e+01, 8.586776177776156e+01, 7.914216892051722e+01, 7.042816656118190e+01, 5.963721086735150e+01, 4.710619586444996e+01, 3.381752868563205e+01, 2.140656408806255e+01, 1.163492190636918e+01, 5.185216750657015e+00, 2.205931050802842e+00, 1.632698836941852e+00, 1.098993452649804e+00, 5.596496824766801e-01, 2.321461100519611e-01, 1.068201387237637e-01, 7.474149535125725e-02, 6.710172150023455e-02, 6.380510875758257e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_ol2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ol2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.503185690655311e+02, 1.442069270613130e+02, 1.358518633969695e+02, 1.246807217584016e+02, 1.102117867617080e+02, 9.230336048154398e+01, 7.152456453107234e+01, 4.952788700707577e+01, 2.910193390504079e+01, 1.353314848182669e+01, 5.395030716096869e+00, 3.395646377840256e+00, 2.628692565996807e+00, 1.655996639199576e+00, 7.125576211431404e-01, 1.640713253458035e-01, -3.059775034457921e-02, -6.693484677547948e-02, -6.676709273157908e-02, -6.380101775760304e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ol2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ol2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.839295297141329e-05, 8.329462903037714e-05, 9.088299630464611e-05, 1.030140017900539e-04, 1.233217920891455e-04, 1.596417752474995e-04, 2.310554591967629e-04, 3.918213494582999e-04, 8.296794093648430e-04, 2.357453922080672e-03, 8.648211354579547e-03, 2.254073298533246e-02, 3.435447611739221e-02, 6.526173532075803e-02, 2.074781812830804e-01, 1.193252773043455e+00, 1.414296335693067e+01, 4.315315626555391e+02, 4.862782266259391e+04, 3.597414593086165e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ol2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ol2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.987314226960548e-01, 6.123285613119324e-01, 6.324860196784682e-01, 6.627785616262656e-01, 7.092250413090991e-01, 7.826091044244424e-01, 9.039840700477992e-01, 1.119610514980530e+00, 1.547824940028221e+00, 2.522231601119564e+00, 4.256890271306476e+00, 4.099902643377789e+00, 4.472973558574751e+00, 5.979747047438077e+00, 1.036593321314274e+01, 2.852675706653101e+01, 1.916613571302539e+02, 4.563610332663026e+03, 4.694829779368145e+05, 3.305246061735833e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ol2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ol2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.201437673185283e-07, -4.756244642060168e-07, -5.683176143631584e-07, -7.336746204138451e-07, -1.057804682301863e-06, -1.785298628320227e-06, -3.768864289154731e-06, -1.091904908805164e-05, -4.925138162054295e-05, -3.990644299914784e-04, -5.375264533632956e-03, -3.568707100092482e-02, -7.834588820602012e-02, -3.013104958709507e-01, -3.086508340612677e+00, -1.024411975233591e+02, -1.440065756054527e+04, -1.340776694642438e+07, -1.702558852835538e+11, -9.317802062910987e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ol2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ol2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.887772944753180e-13, -2.154151950170199e-13, -2.604086927613546e-13, -3.419381159775334e-13, -5.053542753551188e-13, -8.839398344030471e-13, -1.963817066945720e-12, -6.124950184812298e-12, -3.119807134937166e-11, -3.466363814495530e-10, -2.064077510538839e-08, -5.682137108433663e-05, -1.934166425901112e-03, -1.573135746961197e-03, -9.661782642582654e-03, -3.252495726519343e-01, -5.567989402798572e+01, -6.541216938354947e+04, -9.960898963890034e+08, -6.165506371535400e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
