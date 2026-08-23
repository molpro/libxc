
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_rmsrpbel_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsrpbel", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.541611982318448e+00, -4.452708509457638e+00, -4.328195511647764e+00, -4.155846791507892e+00, -3.921286383770179e+00, -3.609733735267179e+00, -3.210143475444979e+00, -2.722744796502899e+00, -2.168828284592404e+00, -1.577613220279875e+00, -1.002846073117472e+00, -6.217117124724117e-01, -5.589186077622115e-01, -4.754079100912454e-01, -3.403479078240319e-01, -2.179012331234544e-01, -1.261261890654440e-01, -4.238120638193611e-02, -8.774367452886237e-03, -9.701687044429635e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_rmsrpbel_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsrpbel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.859495526421365e+00, -5.737417971227069e+00, -5.566217885940139e+00, -5.328763423503887e+00, -5.004548937160259e+00, -4.571584629356753e+00, -4.010872319641050e+00, -3.313249225443708e+00, -2.477594129586485e+00, -1.454828352404400e+00, -9.695425353023346e-01, -8.138667790865844e-01, -7.504907790478806e-01, -5.960206911484925e-01, -3.493185036194248e-01, -1.796649811887859e-01, -1.265779226126515e-01, -5.650827376475220e-02, -1.169915660384832e-02, -1.293558272590618e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsrpbel_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsrpbel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.120535521722156e-06, -2.301279632631257e-06, -2.588572326063046e-06, -3.065860647645682e-06, -3.911434927218805e-06, -5.558035528928563e-06, -9.257546348503888e-06, -1.974097945975209e-05, -6.573794182810946e-05, -4.926997946216276e-04, -1.428707056966446e-03, -5.530836857671972e-03, -1.225214923902884e-02, -4.962280028825487e-02, -2.100610654655947e-01, -6.742939271445894e-01, -3.289040603678669e+00, -3.185798909405011e-06, -2.838770638175765e-188, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsrpbel_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsrpbel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.010896220528328e-05, 4.444590499871003e-05, 5.155627345686461e-05, 6.391321465292988e-05, 8.728613944788300e-05, 1.372997581233189e-04, 2.653959861561197e-04, 6.912126126968923e-04, 2.735054625160270e-03, 1.507579444075077e-02, 5.307533450283167e-03, 4.690868312295016e-03, 1.523124477144874e-02, 5.593955605596249e-02, 7.349710021996721e-02, 1.027394738726448e-02, 5.340125089788737e-03, 2.287252935302073e-12, 2.431808731651629e-198, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsrpbel_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsrpbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.160744867580661e-02, -1.208121777647014e-02, -1.279087737302075e-02, -1.387034144354013e-02, -1.554322470250203e-02, -1.818045345335908e-02, -2.230691473560458e-02, -2.784485161129244e-02, -2.824102679773922e-02, -1.666821543353064e-01, -4.646978851081364e-01, -8.093650665493490e-01, -1.226068528705854e+00, -1.594746093874355e+00, -5.091175313688162e+00, -3.272005228952731e+01, 1.164226063836384e+02, -5.852398323178795e+02, -1.365370822982718e+04, -1.116831697629218e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsrpbel_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsrpbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.134061375986055e-09, -6.842102319712698e-09, -1.009120842979225e-08, -1.700639096908300e-08, -3.418808651213400e-08, -8.700850556797471e-08, -3.046649767192530e-07, -1.644356099206432e-06, -1.545974908930267e-05, -6.163132866258416e-05, 4.721869063258097e-04, 5.943883260731149e-03, -5.731918101014045e-02, 2.779455119122674e-01, 4.160301323187660e+00, 5.195939345851351e+02, -5.299804837240939e+03, -5.271739983043621e+00, -1.180730045515561e-178, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsrpbel_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsrpbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.879455056567934e-05, 3.243331041803003e-05, 3.847356805279902e-05, 4.914829301265959e-05, 6.978721265742318e-05, 1.151724800510220e-04, 2.350770193244690e-04, 6.450483469449254e-04, 2.598449455554458e-03, 6.220974805360282e-03, 2.711579775976628e-03, 2.589705725912037e-02, 3.074283165619767e-01, -4.882246070074017e-02, -6.589377868790793e-01, -4.740399690511158e+01, -6.259126316129415e+01, 8.438910879161058e-07, 9.402729026130080e-189, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsrpbel_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsrpbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.921809789372051e-13, 7.558934383183004e-13, 1.073361112857541e-12, 1.775739054038033e-12, 3.655803627834217e-12, 1.028559494893525e-11, 4.514992854601685e-11, 3.725411139231617e-10, 7.416264220676315e-09, 2.066126128278501e-07, -1.571060905946175e-06, -3.255905644533402e-05, -1.666659907755117e-02, 1.783381220446436e-02, -4.899421234631295e+00, -9.828372872471935e+03, -9.470152113296683e+05, 1.214754626982293e+04, 3.218411870808953e-173, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsrpbel_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsrpbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.364517243505525e-10, -1.004276192473832e-09, -1.305959686884966e-09, -1.904134065872431e-09, -3.270258031662231e-09, -7.096059873436806e-09, -2.148010681767406e-08, -1.042568699025020e-07, -9.751261284625036e-07, -8.912732863318715e-06, 4.097562892580444e-05, 5.548632302908960e-04, 5.651661270806946e-02, -9.456492730482763e-03, 3.238694299092332e+00, 9.507508504177370e+02, 1.829454753810926e+04, 1.125627102078618e-02, -2.220122861222140e-183, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmsrpbel_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmsrpbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.198147774942340e-06, 1.353093218379210e-06, 1.611364682143641e-06, 2.070584728733475e-06, 2.966557452973621e-06, 4.964387343972463e-06, 1.036218037777225e-05, 2.958038320208045e-05, 1.299409825099232e-04, 3.947514502405783e-04, -6.035169763799351e-04, -3.078515562228392e-03, -1.879364224178356e-01, -7.612408585105261e-03, -1.950677041793191e+00, -8.902448822911676e+01, -1.611647818580434e+02, -5.111779683086435e-06, -1.203034615307301e-189, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
