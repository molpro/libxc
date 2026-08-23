
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_acgga_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_acgga", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.689606769341140e-02, -6.587596771374502e-02, -6.441295409871596e-02, -6.231738852211820e-02, -5.932167396780584e-02, -5.505387650977334e-02, -4.901805055002299e-02, -4.064219779743546e-02, -2.967487791234315e-02, -1.789848385206601e-02, -1.331054150430636e-02, -4.407852117709774e-02, -5.290440862189777e-02, -3.759386619534096e-02, -2.051318608582899e-02, -5.941475332481542e-03, -4.628952805943143e-04, -5.846722955360356e-06, -6.826837321847554e-09, -2.546190014670743e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_acgga_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_acgga", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.317820309499891e-01, -1.308495943409555e-01, -1.294978931947006e-01, -1.275304531814866e-01, -1.246479635688328e-01, -1.203784979374416e-01, -1.139368152875649e-01, -1.039254159483666e-01, -8.788387588953954e-02, -6.424685966329624e-02, -5.171569055667112e-02, -8.784154332831778e-02, -8.202777163734498e-02, -7.837799484403918e-02, -6.075862787219571e-02, -2.613214312801805e-02, -2.633283085242383e-03, -3.601391175772914e-05, -4.321334995393504e-08, -1.654255393003964e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_acgga_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_acgga", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.790117535220615e-07, 7.246980297715279e-07, 7.956345538489127e-07, 9.094401737936872e-07, 1.100647113926531e-06, 1.443253595768605e-06, 2.113483728239159e-06, 3.583835664392154e-06, 7.285414707051421e-06, 1.857341105884910e-05, 1.019493477048980e-04, 3.288092948627348e-03, 9.014969503909341e-03, 1.416683552963133e-02, 3.690928845695617e-02, 1.068426622393838e-01, 1.450543463768336e-01, 6.608622374245211e-02, 9.473539206560036e-03, 2.798433387888252e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_acgga_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_acgga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.662966556644237e-04, -2.875771037989434e-04, -3.211883519582449e-04, -3.765275197935468e-04, -4.733091059789562e-04, -6.581239786457837e-04, -1.059181244513684e-03, -2.102330160587716e-03, -5.501382971353983e-03, -1.842246324518065e-02, -6.538675339910244e-02, -2.354281810393252e-02, 7.161258237990635e-03, -6.850320457822011e-02, -8.175600913267743e-01, -5.925210931742011e+00, -1.202288207382514e+01, -5.743464458074161e+00, -8.041370384186166e-01, -2.348581772321023e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_acgga_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_acgga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.557022508562703e-09, 2.951902090860848e-09, 3.628282628597394e-09, 4.879488885542381e-09, 7.466065747054149e-09, 1.374610360106974e-08, 3.299478292179440e-08, 1.155078929484164e-07, 6.770272782231905e-07, 7.325309894901934e-06, 1.724168183531905e-04, 7.934905872597738e-04, -1.173996246686150e-02, 1.109911672207023e-02, 7.014478480800800e-01, 3.109576030776640e+01, 8.033752205702690e+02, 1.258971566525109e+04, 2.093782874773402e+05, 4.694179769904319e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_acgga_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_acgga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.285135612368112e-14, -1.128456245826431e-13, -1.493447960586837e-13, -2.233422867039974e-13, -3.978655425585887e-13, -9.099215391456780e-13, -2.969356607988167e-12, -1.602902875637464e-11, -1.750398625978157e-10, -5.029986390362883e-09, -7.366897392161212e-07, -7.105381365092396e-04, -7.375989520350690e-03, -4.133719187052280e-02, -1.472075530743548e+00, -2.453949631660691e+02, -7.046382340672589e+04, -3.541751697147946e+07, -6.993264752916492e+10, -1.201684510086814e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
