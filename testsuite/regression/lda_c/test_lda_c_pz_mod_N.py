
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pz_mod_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pz_mod", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.184008294441798e-01, -1.177980521908859e-01, -1.169330209316680e-01, -1.156930235872483e-01, -1.139185065466881e-01, -1.113854822076815e-01, -1.077836692159041e-01, -1.026934541695503e-01, -9.557905206232829e-02, -8.587465833359675e-02, -7.310662360483323e-02, -5.903799557372948e-02, -5.525390531178646e-02, -5.154600502321054e-02, -4.358727441129193e-02, -3.200331716665360e-02, -1.895555528143173e-02, -8.176851955595353e-03, -2.273899605821962e-03, -3.222098122603434e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pz_mod_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pz_mod", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.282502027277529e-01, -1.282525541663322e-01, -1.276370077591998e-01, -1.276419992333318e-01, -1.267557703779187e-01, -1.267664862993605e-01, -1.254897017765386e-01, -1.255130861924189e-01, -1.236712069924485e-01, -1.237234604535175e-01, -1.210589117952723e-01, -1.211797710525657e-01, -1.173005214842255e-01, -1.175945045837663e-01, -1.118605136873577e-01, -1.126303055086780e-01, -1.038322254083609e-01, -1.060741903385544e-01, -9.133306827997856e-02, -9.883871762058551e-02, -7.089072795209476e-02, -9.788287050680765e-02, -5.183613946719897e-02, -1.122182840627603e-01, -4.841724736068796e-02, -1.100386334348823e-01, -4.537417428094023e-02, -1.003934475792077e-01, -3.895609738502494e-02, -8.943449570527973e-02, -2.948079027658051e-02, -7.403715203705433e-02, -1.863254343982125e-02, -5.244546634086892e-02, -8.955091877431773e-03, -2.735057281383060e-02, -2.776981182594222e-03, -8.310944750782142e-03, -4.179757348131114e-04, -1.129371905844807e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pz_mod_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pz_mod", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.835191379399325e-04, -5.951854151331165e-04, 4.835431324764632e-04, 5.110427596037255e-04, -6.296951453914608e-04, 5.110968877216569e-04, 5.533141105347450e-04, -6.827842176269164e-04, 5.534409263204857e-04, 6.201080555895011e-04, -7.668818798888599e-04, 6.204217872574453e-04, 7.300233815552920e-04, -9.058071000132866e-04, 7.308626712600896e-04, 9.216419144322836e-04, -1.149500834545185e-03, 9.241541710901353e-04, 1.283988697197549e-03, -1.615212377191521e-03, 1.292824735247676e-03, 2.050446511610018e-03, -2.620358804201554e-03, 2.089594787280609e-03, 3.921981675235804e-03, -5.190826176364770e-03, 4.162396841083688e-03, 9.081605276840323e-03, -1.334680948005203e-02, 1.135520008658042e-02, 1.921164538894200e-02, -4.236517799166648e-02, 4.956351616501299e-02, 1.620963677913038e-02, -9.312569336293233e-02, 2.143241458775718e-01, 1.952199956926051e-02, -1.325676873700453e-01, 3.309795648529075e-01, 3.954507423883592e-02, -2.356750186796635e-01, 5.678160534754709e-01, 8.642635975643007e-02, -6.592985973157364e-01, 1.639587660673091e+00, 1.821027733171048e-01, -2.979148141542551e+00, 8.412696991161781e+00, -6.593462956349624e-01, -2.319836229169765e+01, 8.275602924481049e+01, -4.176782501757196e+01, -3.431985514127650e+02, 1.807956249388073e+03, -2.366473584527949e+03, -1.115742101887531e+04, 1.106310271394441e+05, -3.252520823848645e+05, -1.073443165212972e+06, 2.678174505246484e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
