
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_t_pbe1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_t_pbe1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.593736473483875e+00, -4.517097747308719e+00, -4.410108881345264e+00, -4.262744525301097e+00, -4.063716582302027e+00, -3.802566056443316e+00, -3.474231813525289e+00, -3.086575481136112e+00, -2.665749203142800e+00, -2.222929480093041e+00, -1.577163887115828e+00, -7.372465230879367e-01, -5.906434252354779e-01, -5.362645376785009e-01, -4.569771623427819e-01, -3.750332126011073e-01, -2.496647296548039e-01, -9.533078992915778e-02, -2.024085194480069e-02, -2.240745633755739e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_t_pbe1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_t_pbe1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.013875567422770e+00, -4.893924633908857e+00, -4.725532715668565e+00, -4.491645111570979e+00, -4.171739405675527e+00, -3.743818545180867e+00, -3.190015985849407e+00, -2.509995489671804e+00, -1.754029682340464e+00, -1.092430395906474e+00, -6.975385518643621e-01, -7.113062088782649e-01, -6.796312017716423e-01, -4.794019279073776e-01, -2.598156164481484e-01, -1.632384865033515e-01, -2.192287715900635e-01, -1.205250871329381e-01, -2.692085003771199e-02, -2.987565535034158e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_t_pbe1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_t_pbe1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.192195827537371e-05, -1.290250668758783e-05, -1.445167144601746e-05, -1.700068889215411e-05, -2.144477906873577e-05, -2.985452509903843e-05, -4.770412999470738e-05, -9.203749709442606e-05, -2.271515035991387e-04, -7.530940966516826e-04, -3.743069037672304e-03, -2.180119456953054e-02, -4.008363110070817e-02, -8.753775179566707e-02, -3.293082036699418e-01, -1.803520511093493e+00, -7.704760659780742e+00, -1.483318219090121e+01, -1.822898611367027e+01, -2.015185815338000e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_t_pbe1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_t_pbe1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.652352212719205e-02, -1.740688727198203e-02, -1.876084896646511e-02, -2.089331913000853e-02, -2.438240145647318e-02, -3.039545952935158e-02, -4.146179028033183e-02, -6.314806039051822e-02, -1.038588188953145e-01, -1.288783832706033e-01, -9.812151287461390e-02, -8.413432826783726e-01, -8.674848780326651e-01, -1.820116473689123e+00, -3.649259370268390e+00, 1.719804165061988e+01, 2.392640518198896e+02, -4.676339012770450e+02, -3.048283885424987e+04, -2.578415408330838e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_t_pbe1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_t_pbe1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.716035700735468e-08, 8.826770773475022e-08, 1.070184809182956e-07, 1.409324044929782e-07, 2.085614401975468e-07, 3.631470643982711e-07, 7.886410893920431e-07, 2.270453779227887e-06, 8.703113356457499e-06, 2.700307127283908e-05, -1.241283450616786e-04, 3.679217758639552e-02, 1.175898171823440e-01, 3.982583537429534e-01, 2.220545283205646e+00, -1.171206471839095e+02, -2.126386874441993e+04, -1.759022237267716e+06, -2.547377562817054e+08, -2.087785726124355e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_t_pbe1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_t_pbe1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.244745785579737e-13, 1.583965814444912e-13, 2.238769988059152e-13, 3.677309210836262e-13, 7.484994966737742e-13, 2.066463179971359e-12, 8.771731337986580e-12, 6.780848223895861e-11, 1.181748945914557e-09, 5.768092166348499e-08, 8.604507902682603e-06, 8.138756881685438e-04, 4.603460809684638e-03, 5.505685016271659e-02, 4.082822415827709e+00, 1.733271908583394e+03, 2.150591412626205e+06, 5.348438109057821e+09, 9.252609475577870e+13, 5.885785731314246e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
