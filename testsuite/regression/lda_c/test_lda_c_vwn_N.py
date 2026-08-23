
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_vwn_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.185824110986292e-01, -1.179948578930828e-01, -1.171517400887820e-01, -1.159432736560605e-01, -1.142140701963561e-01, -1.117459500286677e-01, -1.082363248369440e-01, -1.032743345544605e-01, -9.632894931227681e-02, -8.682166949228860e-02, -7.435702126730009e-02, -6.106517815980538e-02, -5.718082919534324e-02, -5.297312886409534e-02, -4.446467026625449e-02, -3.255099674051103e-02, -1.931327672456639e-02, -8.315695886277528e-03, -2.288267140954736e-03, -3.201027765314254e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_vwn_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.281835946550604e-01, -1.281853993730181e-01, -1.275855125824340e-01, -1.275893465858065e-01, -1.267263448379109e-01, -1.267345853875550e-01, -1.254927397711500e-01, -1.255107525906126e-01, -1.237225385460096e-01, -1.237628871140286e-01, -1.211834014146205e-01, -1.212770571342302e-01, -1.175392906640085e-01, -1.177682883036122e-01, -1.122878579268565e-01, -1.128920689964390e-01, -1.046036138702840e-01, -1.063830229303162e-01, -9.284397760024383e-02, -9.889505337933900e-02, -7.411238194311663e-02, -9.630952175333499e-02, -5.609760845610089e-02, -1.089877633208476e-01, -5.242580390877485e-02, -1.072116386572624e-01, -4.900073020832573e-02, -9.744458545531580e-02, -4.143399279778009e-02, -8.630740924478879e-02, -3.079758093321253e-02, -7.195179188983890e-02, -1.911063322486197e-02, -5.255200975181273e-02, -9.080205068664979e-03, -2.835464557545036e-02, -2.801743069393066e-03, -8.286828716335194e-03, -4.165456240282969e-04, -9.736084680786379e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_vwn_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.594654074156011e-04, -4.684350896904688e-04, 3.594840862151732e-04, 3.802226673140067e-04, -4.959897237711311e-04, 3.802648409374362e-04, 4.121354827142489e-04, -5.384241242347246e-04, 4.122344159255125e-04, 4.626379843851305e-04, -6.057469638173545e-04, 4.628831862517021e-04, 5.459262716943810e-04, -7.172085422209247e-04, 5.465839773457157e-04, 6.915850531004144e-04, -9.133609280470519e-04, 6.935613832176543e-04, 9.682802142419697e-04, -1.289993882739667e-03, 9.752704125101153e-04, 1.557348134223278e-03, -2.108527948947740e-03, 1.588571548191704e-03, 3.008033078160971e-03, -4.223057442744163e-03, 3.202025869250836e-03, 7.037507611516883e-03, -1.102968705486471e-02, 8.900887846179643e-03, 1.488961706511791e-02, -3.594906949776295e-02, 4.039542302378794e-02, 1.589785559565349e-02, -9.561529380273165e-02, 2.264496208691799e-01, 2.044273487040017e-02, -1.415117314086388e-01, 3.662209662088894e-01, 3.647926055587067e-02, -2.486965807461179e-01, 5.996506353471299e-01, 8.283299925480128e-02, -7.021464777755310e-01, 1.797300114504483e+00, 2.100412484965528e-01, -3.317056961786258e+00, 1.019280901666322e+01, -2.897411251470246e-01, -2.700921321243792e+01, 1.118748582780858e+02, -3.939542466814117e+01, -3.914266237445998e+02, 2.366918510308520e+03, -2.393008438438550e+03, -1.157741264417922e+04, 1.068620212769827e+05, -3.267964395981855e+05, -9.632713445743467e+05, 2.022646435061374e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
