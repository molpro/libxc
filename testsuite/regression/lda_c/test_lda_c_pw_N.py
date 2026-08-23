
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pw_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.181005011829478e-01, -1.175104821820210e-01, -1.166639079763483e-01, -1.154506642219607e-01, -1.137150125302546e-01, -1.112385552648997e-01, -1.077190571600902e-01, -1.027477541200057e-01, -9.580040348603236e-02, -8.631601320048872e-02, -7.392021676983228e-02, -6.067098172601217e-02, -5.681216702908772e-02, -5.265649831780117e-02, -4.422993759728798e-02, -3.238747607340153e-02, -1.916574958217153e-02, -8.247096145764209e-03, -2.295605136947025e-03, -3.268687243168521e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pw_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.277423596486344e-01, -1.277441548471419e-01, -1.271410275262550e-01, -1.271448414121721e-01, -1.262772392649484e-01, -1.262854369238312e-01, -1.250371083781514e-01, -1.250550286354033e-01, -1.232577926008092e-01, -1.232979381361230e-01, -1.207061770195024e-01, -1.207993782213946e-01, -1.170456279937885e-01, -1.172735863084037e-01, -1.117742626378313e-01, -1.123760849193939e-01, -1.040704953227132e-01, -1.058449324456744e-01, -9.230228118593395e-02, -9.835110789829875e-02, -7.356814053433346e-02, -9.585828232670333e-02, -5.559495855621614e-02, -1.086555804375248e-01, -5.194264469220709e-02, -1.069286919450934e-01, -4.851383692826763e-02, -9.735936052883695e-02, -4.099348285074155e-02, -8.649784046872934e-02, -3.046518174693456e-02, -7.238355525582632e-02, -1.892155312018978e-02, -5.261451828627992e-02, -9.011215793714984e-03, -2.788621961729317e-02, -2.803604220956594e-03, -8.328844608274552e-03, -4.244147288758577e-04, -1.033092066535496e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pw_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.569838952335597e-04, -4.665496227725551e-04, 3.570024843715779e-04, 3.776094727260954e-04, -4.940053209206457e-04, 3.776514461508927e-04, 4.093225063842292e-04, -5.362895611185579e-04, 4.094209778748477e-04, 4.595153342252700e-04, -6.033794470786308e-04, 4.597594218047524e-04, 5.423097273148253e-04, -7.144688088880748e-04, 5.429645707762741e-04, 6.871525620477105e-04, -9.100037005951995e-04, 6.891209090841514e-04, 9.624516947500975e-04, -1.285569443693754e-03, 9.694173518043308e-04, 1.549133183221957e-03, -2.102227999672811e-03, 1.580276391316053e-03, 2.996679455739193e-03, -4.214011393297915e-03, 3.190519929131282e-03, 7.032681055215143e-03, -1.102484324523945e-02, 8.901211629807369e-03, 1.494142429016969e-02, -3.601602158516062e-02, 4.065887889935672e-02, 1.547571931534270e-02, -9.426589386258828e-02, 2.236263199995297e-01, 1.974680153001445e-02, -1.389934957723575e-01, 3.600495805262970e-01, 3.546443663287623e-02, -2.448730459501829e-01, 5.921131182451386e-01, 7.993920406134850e-02, -6.889615092231725e-01, 1.767006529255837e+00, 1.916860539503425e-01, -3.212450034200057e+00, 9.774208025662114e+00, -4.731938910825098e-01, -2.551246311177329e+01, 1.004677286121122e+02, -4.038113830987234e+01, -3.681855365671463e+02, 2.092455733236832e+03, -2.373000676162706e+03, -1.144654210466724e+04, 1.098366930643021e+05, -3.301227712161403e+05, -1.008237164060215e+06, 2.235274533513035e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
