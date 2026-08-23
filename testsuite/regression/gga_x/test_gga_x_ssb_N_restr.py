
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ssb_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.488071070962429e+00, -4.400380137257291e+00, -4.277903712322134e+00, -4.109140328844518e+00, -3.881240392062246e+00, -3.582756401735004e+00, -3.209821708192502e+00, -2.775732207690641e+00, -2.313483229409055e+00, -1.845691865262085e+00, -1.265890769759605e+00, -6.813409442436625e-01, -5.852056265401526e-01, -4.755074054155379e-01, -3.465597171914510e-01, -2.225473094449915e-01, -1.181257200720498e-01, -4.171568120005104e-02, -8.767799959277924e-03, -9.701600531300205e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ssb_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.786267630902469e+00, -5.653085195854128e+00, -5.464693322774180e+00, -5.200020340200882e+00, -4.831815587695517e+00, -4.327592673357759e+00, -3.658776992642975e+00, -2.838532484685490e+00, -1.984978522769608e+00, -1.241870574572668e+00, -7.999230320485631e-01, -8.409985348700406e-01, -7.855610171275490e-01, -5.775886922105234e-01, -3.571267462058190e-01, -2.134388064147801e-01, -1.290035806353589e-01, -5.390512898976436e-02, -1.167283201787857e-02, -1.293521723268640e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ssb_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.123040595889146e-06, -2.447397075480736e-06, -2.994253423898461e-06, -3.977584944483646e-06, -5.905017735875236e-06, -1.011907341861452e-05, -2.054635300942555e-05, -4.947193348790594e-05, -1.389647688404368e-04, -4.939306441073974e-04, -2.453079190188999e-03, -6.072401761901490e-03, 6.745479226782595e-04, -2.374486491971791e-02, -1.040391901980706e-01, -4.521919727487149e-01, -1.938129167946769e+00, -3.872622711923935e+00, -4.789488538952416e+00, -5.295201494190993e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ssb_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.688723491679131e-02, -1.810399881606099e-02, -2.002520935627020e-02, -2.316825558605943e-02, -2.853046850059023e-02, -3.800616159937935e-02, -5.446771357883606e-02, -7.850101787858452e-02, -1.077710207772855e-01, -2.063547057755803e-01, -4.337093972076730e-01, -9.752480984153620e-01, -7.242710968284212e-01, -2.036831520861241e+00, -1.897518246334534e+00, -7.596243370705924e-02, 3.214282785189879e+01, -3.561395952621534e+02, -1.337786737483255e+04, -1.116541297924490e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ssb_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.564307091611975e-08, 7.907287998339876e-08, 1.028634749458649e-07, 1.486254872227987e-07, 2.465839116915817e-07, 4.844831636117886e-07, 1.133501852606674e-06, 2.976139286170651e-06, 8.651317920334416e-06, 5.627150833864480e-05, 8.421042498052745e-04, 4.385816145818989e-02, 3.706528008339919e-02, 4.335286549060597e-01, 1.337191969089925e-01, -3.230457821854017e+01, -5.147234176970771e+03, -4.555040352334622e+05, -6.673767264921305e+07, -5.472861581833587e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ssb_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.348004665692514e-13, -6.824416979330152e-13, -9.636982417863399e-13, -1.563640425408558e-12, -3.048517060312730e-12, -7.436477784299637e-12, -2.248853849736949e-11, -6.433080728229374e-11, 2.988535044233426e-10, 2.169928196686280e-08, 2.789959222436955e-06, -2.698163554084074e-03, -1.768997066535246e-02, -1.189057700756786e-01, 1.631932611868478e+00, 4.427280110274501e+02, 5.261463776923351e+05, 1.386757419780125e+09, 2.424194295232720e+13, 1.542884139676713e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
