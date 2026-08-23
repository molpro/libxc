
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_m05_2x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05_2x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.363346200546513e-02, -6.342455428230208e-02, -6.312664974347976e-02, -6.270287869292412e-02, -6.210062765806237e-02, -6.123869754613349e-02, -5.995755185631341e-02, -5.777437559549607e-02, -5.261240254066624e-02, -3.585759940392386e-02, -6.115068390277429e-03, -6.011787357995357e-02, -5.185659884146746e-02, -4.210186593928348e-02, -2.452511148463372e-02, 6.046507550854241e-03, 6.343092531313831e-02, 5.255243819613863e-02, 1.493856030004086e-02, 1.853957783625165e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_m05_2x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.064827771528206e-01, -1.063892685729580e-01, -1.062573279808870e-01, -1.060530406012981e-01, -1.056683889253240e-01, -1.047486775656202e-01, -1.022199808987425e-01, -9.557121449018743e-02, -8.336943925502209e-02, -8.438412283692805e-02, -1.325886082961174e-01, -7.225133303966509e-02, -5.150902520653257e-02, -6.943051056066041e-02, -6.313297122014014e-02, -5.539706571729120e-02, 1.190151431148031e-02, 8.117022218104465e-02, 2.777586054201564e-02, 3.712103255111936e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_2x_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.188621094842752e-06, 1.270498968399541e-06, 1.397775137103973e-06, 1.601426766183139e-06, 1.938714764327790e-06, 2.514861913611447e-06, 3.489210795822620e-06, 4.805845580534061e-06, 4.122085250940971e-06, -5.887140886639499e-06, 1.905990451302043e-04, 8.853348434416629e-04, 2.818226262492537e-04, 1.595381345298833e-02, 2.150788291975905e-02, -5.009975688604543e-02, -9.940643461043066e-01, -1.346721136063241e+02, -6.135610422901118e+03, -7.085786185345157e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_2x_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.782862948070837e-03, -1.792325340320390e-03, -1.805240358609639e-03, -1.821216228065604e-03, -1.835162918223508e-03, -1.825235779254232e-03, -1.716633423426881e-03, -1.297510754189377e-03, -1.753486339712231e-04, 1.559802086397287e-03, 1.708213832901863e-03, -5.303708103772569e-04, -2.980222230949341e-03, -1.228938806420663e-02, 7.667919015970249e-03, 4.898622707499498e-02, 6.081837374237545e-02, 3.878884120078556e-02, 1.363227787796946e-02, 2.150689719840370e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_2x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.494577367990328e-04, 2.653431580683814e-04, 2.833225667231922e-04, 2.944266902234242e-04, 2.626846043916808e-04, 5.246846343407295e-05, -8.462051168737403e-04, -4.275439674147989e-03, -1.532253494970209e-02, -3.427714502568154e-02, -5.719020262446307e-02, 3.077648707620283e-01, -1.041429817900525e-01, 3.912944643582336e-01, -1.584201804236283e+00, 5.643066407815992e-01, -2.398988068235336e+02, -5.730936559466020e+02, 3.385346380068833e+04, 4.061610553518219e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_2x_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.571618985918972e-09, -6.270970998646248e-09, -7.271486702674807e-09, -8.520465868753161e-09, -9.028487939008317e-09, -2.002452634775835e-09, 5.774591518682101e-08, 5.054455933263457e-07, 4.150606270482432e-06, 3.540318069126837e-05, 4.343365017143578e-04, -2.549693150905915e-02, 3.099345187579379e-02, -1.102929878059739e-01, 3.536689047151724e+00, 4.207442596334340e+01, 1.700272731044833e+04, 2.034933836592916e+06, -5.242827727163541e+09, -5.658389173344128e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_2x_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.448097348403188e-06, 5.711453262320597e-06, 5.957548633129443e-06, 5.919515650281485e-06, 4.617809373482689e-06, -1.539324291889267e-06, -2.615469616198713e-05, -1.210194425937116e-04, -4.614150039396558e-04, -1.442692546668279e-03, -3.615793841101309e-03, -2.767825552565961e-04, 2.571778772517502e-03, -7.871876085959736e-02, -1.425627669577676e+00, -6.279440301048704e+00, -7.805858555402673e+00, 2.325299826384359e+02, 1.286866212780936e+04, 1.718985670678951e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_2x_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.018226483280985e-13, 1.220610957233476e-13, 1.553678965592927e-13, 2.095709727239204e-13, 2.790419015877841e-13, 1.617163812517650e-13, -2.649533784453582e-12, -4.381151379187643e-11, -8.413825718524345e-10, -2.707948992474683e-08, -3.131806706449158e-06, 2.024981588014186e-03, -3.997418887425453e-03, 1.781864524909320e-02, -6.294096955730941e+00, -9.543418649762814e+02, -2.146837689193397e+06, -9.932702543046009e+09, -2.296193598146248e+14, -1.671824244492430e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_2x_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.521729725728827e-10, -3.997081274052143e-10, -4.774224997102916e-10, -6.100027723843792e-10, -8.454360583685661e-10, -1.258414214870127e-09, -1.727398134913953e-09, 1.162709298852209e-09, 5.457049430511672e-08, 8.756118131327823e-07, 1.750585306950456e-05, -1.694273435013288e-04, -8.474584219000195e-03, -3.057220488135724e-02, 1.646305007311598e+00, 9.735513567593964e+01, 1.252230169016560e+04, 7.336764032151801e+06, 3.467454909067379e+10, 3.140867233520282e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_2x_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.099908537393494e-07, 8.670946799980189e-07, 9.558868648691723e-07, 1.097917479820330e-06, 1.332607284821105e-06, 1.729979098687137e-06, 2.379338227232063e-06, 3.084810485782957e-06, 8.927393626811178e-07, -2.309659906507860e-05, -1.114221309149376e-04, 2.486862912052539e-04, 9.621889535305916e-03, 1.120967180983328e-01, -2.367069785117313e-01, -9.572916920868639e+00, -1.591132867038646e+02, -3.502619894292217e+03, -1.529536299231981e+05, -1.906488582068055e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
