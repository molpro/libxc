
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_b94_hyb_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.005525924214539e+00, -2.989734279171587e+00, -2.963925969574274e+00, -2.921227814521835e+00, -2.850455692902296e+00, -2.734639407017314e+00, -2.551054585218572e+00, -2.277855809596575e+00, -1.913892266031632e+00, -1.491260961821036e+00, -1.042011305960714e+00, -6.232379461714387e-01, -4.970487536078891e-01, -4.273867250741210e-01, -3.324947928652610e-01, -2.266606719700993e-01, -1.449533871574120e-01, -9.338426073104442e-02, -6.208746155611571e-02, -4.219009796989555e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_b94_hyb_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.152269043278870e+00, -4.192336332859726e+00, -4.231346589237116e+00, -4.250644427104846e+00, -4.207849319230467e+00, -4.021585570705482e+00, -3.588830897684317e+00, -2.923883987794666e+00, -2.212178212999755e+00, -1.563603450006467e+00, -1.048735584576672e+00, -7.914707965151506e-01, -6.839458091044183e-01, -5.714631276301160e-01, -3.773117523516752e-01, -2.174432303303459e-01, -1.079110654798904e-01, -5.219447432624180e-02, -2.789639377303496e-02, -1.623994006592755e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b94_hyb_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.155873118255889e-07, 9.136729121547827e-08, -1.905266618637134e-07, -8.481416790047768e-07, -2.424482520293743e-06, -6.220843594639138e-06, -1.476912624432676e-05, -3.163331552778192e-05, -6.751833179333128e-05, -1.833386109518957e-04, -7.837099657050484e-04, -3.724002748060600e-03, -1.846437820670973e-03, -1.922576862617761e-02, -6.660868513904958e-02, -3.551894214274505e-01, -4.214601437985822e+00, -1.166181311810369e+02, -1.032611974407226e+04, -5.635657618033110e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b94_hyb_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.962325508346757e-05, -8.102718347897231e-05, -1.644822710175142e-04, -3.293969806750822e-04, -6.416573814001503e-04, -1.173989281912245e-03, -1.864570109500579e-03, -2.331321497082551e-03, -2.354555874289246e-03, -2.268997316026563e-03, -2.688873417812994e-03, -5.762076926632013e-03, -3.880133449553561e-03, -1.030877525641697e-02, -1.076437392406343e-02, -9.914483421837504e-03, -9.196142722709947e-03, -7.702466539034958e-03, -5.908586765319598e-03, -4.351695797883900e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b94_hyb_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.088705222687357e-04, -1.231278557035824e-04, 2.351378154806269e-04, 9.225419425170672e-04, 2.200125134690653e-03, 4.354376437721158e-03, 7.131190301591897e-03, 8.993095400202170e-03, 9.053754265430801e-03, 8.645849526101078e-03, 1.007270529617331e-02, 1.845117688956458e-02, 6.073662476333019e-03, 3.285167149445743e-02, 3.570141481561612e-02, 3.307884881572063e-02, 3.311157360968051e-02, 3.002695117188634e-02, 2.359444823096152e-02, 1.740650579974333e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b94_hyb_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.006213446409615e-02, -1.177888952307391e-02, -1.414297031979605e-02, -1.717835222175564e-02, -2.043296996426065e-02, -2.278059116654271e-02, -2.671829618761894e-02, -4.311071955443296e-02, -6.754484627547643e-02, -1.132479229283212e-01, -2.430196935614019e-01, -5.610660978672791e-01, -8.961572797262138e-01, -1.092207158325490e+00, -2.419217716707227e+00, -7.072832392009091e+00, -2.720758535074317e+01, 3.722501281300268e+01, 2.024901294380088e+04, 1.150030279418917e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b94_hyb_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.736660309826359e-09, -6.656972917413926e-09, -1.062659584120964e-08, -1.868827192439251e-08, -3.125985379793923e-08, -1.644545427428491e-08, 2.399027408339584e-07, 1.116224324851843e-06, 2.540444826728163e-06, 9.451342515897069e-06, 1.519166117491753e-04, 3.092785775436584e-04, -3.318446295573484e-02, 9.480681899638166e-02, 5.869555701835574e-01, 1.513369504371805e+01, 1.279991632284260e+03, 2.450033497814618e+05, 1.349332979850064e+09, 1.279425273530200e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b94_hyb_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.370126656599186e-07, -1.345063690854715e-06, -2.827813646714102e-06, -5.791534461123576e-06, -1.075995014839742e-05, -1.393833416046108e-05, 8.494636331074607e-07, 1.696407171539287e-05, -5.150656280800799e-05, -2.710834138275458e-04, -1.196691048407852e-03, -5.577026209968473e-03, -2.283011718918862e-02, 8.925182240375674e-03, -7.174789077341448e-02, -5.705264505599510e-01, -8.095385047411755e+00, -2.354594914103517e+02, -1.999856248768165e+04, -1.028403985933821e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b94_hyb_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.061483546058445e-06, 8.240092658432924e-06, 1.463898950342229e-05, 2.711276867294133e-05, 4.776298158802577e-05, 6.127800081001428e-05, 2.317308474467160e-06, -6.426701081623118e-05, 1.994900863425002e-04, 1.021004162419402e-03, 4.317157329978364e-03, 2.825965100399000e-02, 1.239282936552884e-01, -8.193224522145409e-03, 2.182687012634240e-01, 1.432111880846838e+00, 2.366069166058053e+01, 8.698613458566465e+02, 7.952582818762674e+04, 4.113357953395696e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b94_hyb_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.078615733494237e-15, -6.519157058192322e-15, -2.282590193191882e-14, -9.076653272341763e-14, -4.103361618013100e-13, -1.957440695768690e-12, -6.766829594343540e-12, 1.585489392736892e-11, 5.529069958343107e-10, 1.340877864190209e-08, 1.051144958539187e-06, -6.305850982599504e-04, -3.774769376306714e-03, -3.850774721637874e-02, 5.939717644330660e-01, 7.242482618572635e+01, 1.796681396651284e+05, 7.123142770348095e+09, 8.792537058944167e+15, 2.560951756463818e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b94_hyb_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.057093016843296e-13, -1.890130093561479e-12, -6.342788376092726e-12, -2.299141529623813e-11, -8.864983109562098e-11, -3.294440732883233e-10, -7.725441669340090e-10, 1.306536206678373e-09, 1.958983506391761e-08, 1.704152186886123e-07, 3.834569240575071e-06, -6.574341354965106e-04, -2.624232589439318e-03, -1.265218414961626e-02, 1.186244460268835e-01, 3.073881825366363e+00, 4.936873965752625e+02, 4.925784128193216e+05, 5.047422207562106e+09, 1.977564237126890e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b94_hyb_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.978019076186523e-12, 8.785308384343491e-12, 2.817050728829583e-11, 9.872870946804286e-11, 3.723643687652462e-10, 1.370141125431417e-09, 3.267325959397496e-09, -4.507417931695780e-09, -7.414111010983016e-08, -6.323287924173332e-07, -1.350993843927757e-05, 3.124336360379204e-03, 1.241670575690104e-02, 6.579939071052851e-02, -3.183613714415814e-01, -6.744935888784138e+00, -1.411543871792384e+03, -1.834073809874233e+06, -2.009032101096435e+10, -7.909852695648341e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b94_hyb_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.672360940914443e-10, -5.336326667970229e-10, -1.741056745619812e-09, -5.792294639547112e-09, -1.910401393518373e-08, -5.535902974242010e-08, -8.790868967499997e-08, 1.056299301138289e-07, 6.920685560442060e-07, 2.154502220931380e-06, 1.378972023158027e-05, -6.611801204855162e-04, -1.763352915361574e-03, -3.782499003780373e-03, 2.112574828729419e-02, 1.038757468691324e-01, 1.246198706410196e+00, 3.389984163755658e+01, 2.897440596256185e+03, 1.527073007868564e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b94_hyb_N_restr_1_v2lapltau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapltau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapltau"])
    tgt = out["v2lapltau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.677957286541209e-10, 2.547166084547450e-09, 7.827930160647011e-09, 2.500825682036631e-08, 8.044633027749203e-08, 2.305995141092712e-07, 3.730186457650073e-07, -3.714376616689963e-07, -2.626865149925813e-06, -8.036410497982535e-06, -4.928415815579948e-05, 3.257364279229230e-03, 8.632136337987205e-03, 2.161918233035614e-02, -6.358120635525971e-02, -2.862711163244879e-01, -3.878603187609013e+00, -1.268295744431902e+02, -1.153300028740168e+04, -6.107979883797115e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b94_hyb_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b94_hyb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.266588323769858e-09, -1.183920600762724e-08, -3.476653335525909e-08, -1.073893403301767e-07, -3.379064192569965e-07, -9.590516369954483e-07, -1.577610131320059e-06, 1.281422411530708e-06, 9.941824302699207e-06, 2.981924844895820e-05, 1.736377415411116e-04, -1.548003230606558e-02, -4.084344405811244e-02, -1.124334745823632e-01, 1.706376782453706e-01, 6.281569806897844e-01, 1.108964619830897e+01, 4.722391293446166e+02, 4.590495275911450e+04, 2.443067094447989e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
