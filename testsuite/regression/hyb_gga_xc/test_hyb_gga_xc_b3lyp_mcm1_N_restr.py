
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b3lyp_mcm1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp_mcm1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.494328375518661e+00, -3.428310855533280e+00, -3.335849785724862e+00, -3.207861803532836e+00, -3.033653380078334e+00, -2.802180740698196e+00, -2.504999630588274e+00, -2.141462100480047e+00, -1.725214469982302e+00, -1.285991029749162e+00, -8.595192756465143e-01, -5.626408455432890e-01, -4.832217388654100e-01, -4.021692707463463e-01, -2.877302550162200e-01, -1.700955981596995e-01, -8.711243070632414e-02, -6.381656989581143e-02, -3.950699821475443e-02, -2.717167532301602e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b3lyp_mcm1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp_mcm1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.391430014884274e+00, -4.300531648836126e+00, -4.173151881656630e+00, -3.996686680539029e+00, -3.756227012953903e+00, -3.436267600449429e+00, -3.024900792433447e+00, -2.521930937352548e+00, -1.952263307995639e+00, -1.384041978591811e+00, -9.252004619590105e-01, -6.947545322802799e-01, -6.170523718831961e-01, -4.945256107815438e-01, -3.430779014467895e-01, -2.111065785180637e-01, -1.044511174422375e-01, -3.164360779220191e-02, -1.121139153510260e-02, -4.395236871640729e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp_mcm1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp_mcm1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.712307919511897e-06, -2.922764596655856e-06, -3.253183648499401e-06, -3.791892821249426e-06, -4.718524451897157e-06, -6.437461668576382e-06, -9.980200243243236e-06, -1.841175493330983e-05, -4.266344925280155e-05, -1.308998451015625e-04, -5.852529543126780e-04, -3.959097987273071e-03, -7.932316590092456e-03, -1.411408776717394e-02, -3.753854589504326e-02, -7.882159582531473e-02, 1.309501186411142e-01, -1.161539316340700e+02, -1.132332952555636e+04, -6.732816568995508e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp_mcm1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp_mcm1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.334137980306389e-03, -9.743884591880053e-03, -1.036372574451023e-02, -1.132186838484506e-02, -1.284880301194890e-02, -1.538754959766729e-02, -1.985648162802746e-02, -2.829896157702777e-02, -4.530363032175279e-02, -7.826074410411459e-02, -1.434174067949606e-01, -4.024024034982991e-01, -5.214484049824036e-01, -8.040951953628258e-01, -1.345577171702477e+00, 4.543263754375255e-01, 1.816719794623153e+01, 1.274936236244847e+01, 1.124424656588815e+04, 6.990432855018343e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp_mcm1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp_mcm1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.349582921568582e-08, 1.529017689239971e-08, 1.827917094668078e-08, 2.358053932437577e-08, 3.385087811898876e-08, 5.633572239556540e-08, 1.143340042253209e-07, 2.973575413892312e-07, 9.763415174252868e-07, 1.686216931454020e-06, -8.817219971075574e-05, 3.761315379807966e-03, 1.631703718872774e-02, 2.711416824024222e-02, -2.541075095835154e-01, -3.623430414031919e+01, -4.992463053049514e+03, -6.997690396897004e+05, -6.781522247933986e+09, -2.288018222311558e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp_mcm1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp_mcm1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.055675065952204e-14, 8.800897837765860e-14, 1.208486639004269e-13, 1.903587671229775e-13, 3.645784761845762e-13, 9.210054688384281e-13, 3.433971950927356e-12, 2.199943272376475e-11, 2.957151085627521e-10, 1.074953870575355e-08, 1.430391635440679e-06, 3.486007993260808e-04, 3.066631124980519e-03, 2.060748040104119e-02, 8.781482484133919e-01, 2.471579617082545e+02, 5.040949461386828e+05, 1.339745259405805e+10, 1.623853227175792e+16, 5.400031669165779e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
