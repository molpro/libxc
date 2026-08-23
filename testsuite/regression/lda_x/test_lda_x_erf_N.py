
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_erf_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_erf", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.996204657088653e+00, -3.912162885506896e+00, -3.794385590015965e+00, -3.631205110863821e+00, -3.408791625632622e+00, -3.112664465258387e+00, -2.731345175551902e+00, -2.263134167033607e+00, -1.726382001955307e+00, -1.173445316215200e+00, -7.171268928689422e-01, -5.165901085421434e-01, -4.379596418883436e-01, -3.247655727084585e-01, -1.860519897744780e-01, -6.912168850610277e-02, -1.105904004771704e-02, -4.865356926790385e-04, -4.784586868730254e-06, -6.680850995279980e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_erf_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_erf", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.383071822772161e+00, -5.383026794209103e+00, -5.271006837161917e+00, -5.270912688486258e+00, -5.113972401771496e+00, -5.113774616657897e+00, -4.896434531193095e+00, -4.896016126055441e+00, -4.600009049031317e+00, -4.599114718522467e+00, -4.205523210430483e+00, -4.203581546115815e+00, -3.698007753033786e+00, -3.693690518835306e+00, -3.076073008772982e+00, -3.066113406448507e+00, -2.366624272229471e+00, -2.342317177264646e+00, -1.646165662181093e+00, -1.582168687877879e+00, -1.071557440122029e+00, -8.996038263757556e-01, -8.076691926091564e-01, -4.967552149911696e-01, -6.915393602948369e-01, -4.022331202602760e-01, -5.250467590125120e-01, -3.027400871662061e-01, -3.161408317669105e-01, -1.607359511387160e-01, -1.293179706174582e-01, -4.493312109654658e-02, -2.301087582032106e-02, -3.728205447120680e-03, -1.022539293691467e-03, -6.694735769089494e-05, -9.756635218744293e-06, -1.991286539004690e-07, -1.341881676450708e-08, -5.766894413571076e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_erf_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_erf", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.065657278853160e-02, -3.522101828684134e-133, -2.065690793523335e-02, -2.151661993298695e-02, -1.761050914342067e-133, -2.151736491093261e-02, -2.281513862956075e-02, -7.044203657368268e-133, -2.281684751738212e-02, -2.481744228879242e-02, 0.000000000000000e+00, -2.482154389051475e-02, -2.799955899541993e-02, -1.056630548605240e-132, -2.801006709249878e-02, -3.327933542730346e-02, -1.408840731473654e-132, -3.330891003054686e-02, -4.259290118025479e-02, -3.522101828684134e-133, -4.268821637139334e-02, -6.049766412469674e-02, -4.226522194420961e-132, -6.087102864905565e-02, -9.913764789080935e-02, 2.817681462947307e-132, -1.010686397214387e-01, -1.936992620828587e-01, 0.000000000000000e+00, -2.081563757709698e-01, -4.159549898033663e-01, -1.690608877768384e-131, -5.617175969748751e-01, -6.734817813182218e-01, -2.254145170357846e-131, -1.465321221379756e+00, -8.698741596072307e-01, -5.635362925894614e-131, -2.005163913544438e+00, -1.346083590432559e+00, -3.381217755536768e-131, -2.979296045468326e+00, -2.810573649529630e+00, 6.762435511073537e-131, -6.373805810366452e+00, -7.937675387298575e+00, -1.803316136286277e-130, -1.698813534514321e+01, -2.223871254087373e+01, 1.803316136286277e-130, -3.068123306266580e+01, -3.307504294043328e+01, -3.606632272572553e-130, -3.460430750964532e+01, -3.482268923140858e+01, -1.081989681771766e-129, -3.490031455366079e+01, -3.490554660888024e+01, -3.606632272572553e-130, -3.490655759042052e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
