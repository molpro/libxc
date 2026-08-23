
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_cam_qtp_02_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_02", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.032082310406663e+00, -2.972837750657347e+00, -2.889850497920174e+00, -2.774949921078002e+00, -2.618494937969269e+00, -2.410469683404698e+00, -2.143040708201469e+00, -1.814975989570468e+00, -1.436824652544012e+00, -1.031657801198307e+00, -6.365546759032199e-01, -3.898373515725998e-01, -3.233902110330518e-01, -2.484561349843563e-01, -1.432370876442904e-01, -4.101533872067582e-02, 7.549876956788028e-03, -3.397362052118500e-03, -9.122718005388404e-04, -1.023980874926886e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_cam_qtp_02_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_02", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.816743527943828e+00, -3.735323498354333e+00, -3.621251634718868e+00, -3.463277633506377e+00, -3.248136202786555e+00, -2.962138421802068e+00, -2.595065081379531e+00, -2.147733635179727e+00, -1.644498517161530e+00, -1.148899407702697e+00, -7.482062439864328e-01, -5.204446262723581e-01, -4.469881692241358e-01, -3.456046011444684e-01, -2.231471366068792e-01, -1.183684577420740e-01, -4.206127988735468e-02, -4.810102534812906e-03, -1.211698704177779e-03, -1.364610149892025e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_qtp_02_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_02", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.720636950495855e-06, -2.927444814679378e-06, -3.251340597829106e-06, -3.777482552566854e-06, -4.677461797699692e-06, -6.332462942262843e-06, -9.695414546976019e-06, -1.750541798903109e-05, -3.894571811360841e-05, -1.093015737877967e-04, -3.966851886550079e-04, -2.369390879037767e-03, -4.333432045864648e-03, -5.397521611624059e-03, 3.952655131172600e-03, 2.588125379164027e-01, 4.221770743446910e+00, 5.243815866490463e+00, -1.917365598260827e-05, -4.325576459774959e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_qtp_02_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_02", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.437122741243088e-03, -8.805091094743032e-03, -9.361043180314353e-03, -1.021873846799806e-02, -1.158116788004693e-02, -1.383365124338328e-02, -1.775707996861198e-02, -2.500938588294691e-02, -3.887110134230681e-02, -6.158571256180334e-02, -9.321886722964566e-02, -3.251736497171020e-01, -4.350092113347848e-01, -6.024766086487907e-01, -7.281480423240669e-01, 1.545929682803183e+00, 1.543319477267389e+01, -8.370077326105927e+01, -1.388281919285014e+03, -1.175178357017724e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_qtp_02_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_02", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.315384320477110e-08, 1.486469409620431e-08, 1.770256699344133e-08, 2.270332234640528e-08, 3.229207470283796e-08, 5.292708775561707e-08, 1.045110551447484e-07, 2.565957389849478e-07, 7.049425359699714e-07, -1.565664822611971e-06, -1.683037949780006e-04, 8.185464978031237e-04, 4.808245491771449e-03, -1.470852865087207e-02, -6.458317644668097e-01, -3.714466701763232e+01, -3.484962647326191e+03, 1.637101386132052e+05, -2.433181265975363e+02, -4.262048829162775e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_qtp_02_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_02", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.110865327566134e-14, 8.858417067989784e-14, 1.214096907689879e-13, 1.907068210100850e-13, 3.636981489848294e-13, 9.127655534877741e-13, 3.367662079225511e-12, 2.119670698377738e-11, 2.759669356354453e-10, 9.417553515797736e-09, 1.111166475135476e-06, 2.407185485811962e-04, 1.963993348894066e-03, 1.155957733537484e-02, 3.404052006931687e-01, 3.049021453668569e+01, 2.647629677640988e+03, 2.533429523352961e+05, 6.625653095653520e+07, 9.011460488033914e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
