
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_2d_b86_mgc_HO2D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b86_mgc", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.488250394385864e-01, -8.488228771926724e-01, -8.488171898915705e-01, -8.488022531570287e-01, -8.487631192125894e-01, -8.486609872962156e-01, -8.483960954683818e-01, -8.477158003496456e-01, -8.459953884294942e-01, -8.417466304937040e-01, -8.316236909530776e-01, -8.087613786927673e-01, -7.610747287131868e-01, -6.728595390728139e-01, -5.369073305808391e-01, -3.682793039657176e-01, -1.865299128809635e-01, -5.984786451580237e-02, -1.207934416880213e-02, -1.238307003230168e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_2d_b86_mgc_HO2D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b86_mgc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.273237558061014e+00, -1.273234311107524e+00, -1.273225764894946e+00, -1.273203295047247e+00, -1.273144320967001e+00, -1.272989980821044e+00, -1.272587933182788e+00, -1.271548489893450e+00, -1.268893713726883e+00, -1.262244741046923e+00, -1.246099831017823e+00, -1.208728010157421e+00, -1.128220795887780e+00, -9.724846188813530e-01, -7.215781043800727e-01, -4.490008541689191e-01, -2.232925437389943e-01, -6.280212896754096e-02, -1.022897360614346e-02, -9.408274774259521e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_b86_mgc_HO2D_restr_1_vsigma():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b86_mgc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.235115177706857e-03, -9.235185718384305e-03, -9.235371206863668e-03, -9.235858146433393e-03, -9.237133080638223e-03, -9.240457364883449e-03, -9.249069839354099e-03, -9.271170454723544e-03, -9.327120574426653e-03, -9.466310318936055e-03, -9.806075735972013e-03, -1.062451337287638e-02, -1.260632851763705e-02, -1.755731044219868e-02, -2.972503140016519e-02, -4.877529269376085e-02, -8.727925307416227e-02, -5.694373261866075e-01, -2.254276812133060e+01, -1.437637861777715e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_b86_mgc_HO2D_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b86_mgc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.000001562055621e+00, -1.000004117852149e+00, -1.000010854104466e+00, -1.000028604284463e+00, -1.000075356361477e+00, -1.000198402753481e+00, -1.000521800807463e+00, -1.001369616851981e+00, -1.003581947250348e+00, -1.009308610901910e+00, -1.023949337553381e+00, -1.060815526182308e+00, -1.152530664397519e+00, -1.376228788097010e+00, -1.789172265138298e+00, -1.570357572606284e+00, -4.437984980309193e+00, -2.161573560699990e+01, 3.738281133570731e+02, 9.442574971432339e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_b86_mgc_HO2D_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b86_mgc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.175979527798946e-02, 2.176007206087799e-02, 2.176079949863580e-02, 2.176270760275312e-02, 2.176769713928278e-02, 2.178068128333261e-02, 2.181422107501837e-02, 2.189992936368178e-02, 2.211575820794855e-02, 2.264979417027290e-02, 2.395033122307803e-02, 2.710347159119455e-02, 3.487223662797310e-02, 5.363429928755307e-02, 6.194913936839454e-02, -5.786147201940692e-01, -6.752008476915093e+00, -8.469609472154110e+02, -7.869394573011880e+06, -4.690502183739947e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_b86_mgc_HO2D_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b86_mgc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.937316964637532e-04, 8.937521853262124e-04, 8.938060772959331e-04, 8.939476247585772e-04, 8.943185613164909e-04, 8.952873014357412e-04, 8.978047268074110e-04, 9.043038571867403e-04, 9.209655014208302e-04, 9.635615606668243e-04, 1.074027880935675e-03, 1.378619258188766e-03, 2.372189742869461e-03, 7.067719075694390e-03, 4.881294676577781e-02, 7.028251438939630e-01, 2.638614578101511e+01, 5.333594497535620e+04, 6.745036060957178e+10, 2.206960688413353e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
