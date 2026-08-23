
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_xc_tpsslyp1w_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_tpsslyp1w", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.793460513444394e+00, -4.697774418651623e+00, -4.563650367643339e+00, -4.377767062441019e+00, -4.124312174717236e+00, -3.786711634913494e+00, -3.351928767544940e+00, -2.818961932029916e+00, -2.213638839506348e+00, -1.605716463375474e+00, -1.061335896012277e+00, -6.974830465905778e-01, -6.075690811835747e-01, -5.211341834750476e-01, -3.709546979814718e-01, -2.285538248463487e-01, -1.171778296908257e-01, -4.732240654299565e-02, -1.031533926006739e-02, -1.161760453797616e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_xc_tpsslyp1w_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_tpsslyp1w", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.854135478670775e+00, -5.743835710017317e+00, -5.589119350829064e+00, -5.374412618290610e+00, -5.080868749249807e+00, -4.687567773431507e+00, -4.173987055808060e+00, -3.522235881860285e+00, -2.717507556955926e+00, -1.801066824346883e+00, -1.090033102483762e+00, -8.915983040995704e-01, -7.841765756701172e-01, -6.398074179502028e-01, -4.480785956695413e-01, -2.437862206402627e-01, -1.628154628582404e-01, -6.159772554353608e-02, -1.369635037165359e-02, -1.547209693360655e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_tpsslyp1w_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_tpsslyp1w", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.474478390561733e-05, -1.518740063638826e-05, -1.583720720462431e-05, -1.679778658477053e-05, -1.822993142868375e-05, -2.039156360993710e-05, -2.376283075007233e-05, -2.987796105633203e-05, -4.900754136836329e-05, -1.665066999074528e-04, -9.838800956527398e-04, -2.082151880075560e-03, -1.465770132850999e-02, -3.989764530556078e-02, -6.529519969257877e-02, -3.278637585094996e-01, 1.158777029005251e+00, 8.576138896744827e-01, -3.575695677223656e+00, -3.945369433645118e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_tpsslyp1w_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_tpsslyp1w", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.096222949058221e-02, 2.030572886291643e-02, 1.938511335860053e-02, 1.810843724123012e-02, 1.636708098853245e-02, 1.405272512964990e-02, 1.111049076445893e-02, 7.678606326853628e-03, 4.358372667814789e-03, 2.242775068684330e-03, 1.635479944022936e-03, -2.068627703938352e-04, 9.197046938864552e-03, 3.502085177636491e-02, 1.703770743330874e-02, 2.665618632296539e-03, 3.230509704348823e-05, 8.201985881843887e-09, 8.209836985028523e-14, 9.720520444427594e-21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_tpsslyp1w_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_tpsslyp1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.551497824615446e-03, -4.631777095709921e-03, -4.753456063377301e-03, -4.947219704312192e-03, -5.288397851215328e-03, -6.012522094260464e-03, -8.043727514218087e-03, -1.570739426503208e-02, -5.017054465997740e-02, -1.710361261693525e-01, -3.521825185501730e-01, -4.310551658362657e-01, -6.967615438461988e-01, -7.130832810171720e-01, -2.505404083913863e+00, 3.932076763259760e-01, 6.609399538774895e+01, -4.825596570565798e+02, -1.557283411681156e+04, -1.328716913788510e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_tpsslyp1w_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_tpsslyp1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.311638394044003e-07, -1.485757179787215e-07, -1.774869291254212e-07, -2.284644098537060e-07, -3.261061121247374e-07, -5.348786945484105e-07, -1.045244454454044e-06, -2.448234382343978e-06, -5.785425535526368e-06, -1.005755705034834e-06, 4.095343095968858e-05, 5.213580968107085e-03, 2.392194824628616e-02, -2.226575518074266e-01, -1.082160589098339e+00, -5.007795119219674e+01, -8.969002031801232e+03, -2.470580122816717e+05, -5.003209673992021e+07, -4.087574386171978e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_tpsslyp1w_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_tpsslyp1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.468601151108586e-04, 1.567303115530259e-04, 1.719256892734805e-04, 1.959697037543522e-04, 2.354371278391838e-04, 3.033133489217503e-04, 4.264133246436990e-04, 6.601860978695589e-04, 1.111736851236341e-03, 1.990110514709032e-03, 3.949868771402024e-03, -7.884991194683846e-03, 1.095198853785561e-02, 2.153375313391468e-01, 9.670321871135692e-01, 1.444125402944993e+00, 7.250732869343966e-02, 3.118799975017569e-03, 9.299970068622383e-06, 1.641631222630633e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_tpsslyp1w_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_tpsslyp1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.679250790308887e-12, 2.063094185055942e-12, 2.766265509567620e-12, 4.194304616205335e-12, 7.547223766580253e-12, 1.717902742874664e-11, 5.358996507586742e-11, 2.507339995307651e-10, 1.920559564743856e-09, 3.086084477545041e-08, 2.580111265405185e-06, -8.352602999264979e-04, -2.326198376334011e-02, 1.520231095537615e-01, 3.601985608728187e+00, 5.323426109972430e+02, 6.145220677938465e+05, 1.112168252971632e+09, 1.816687196590039e+13, 1.152344679756801e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_tpsslyp1w_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_tpsslyp1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.059098333549006e-09, 2.156048486237243e-09, 2.284881086878657e-09, 2.432856578356636e-09, 2.505856091322876e-09, 2.037645008741693e-09, -1.293910566043105e-09, -2.054778924994312e-08, -1.429981276134345e-07, -1.016229428386943e-06, -6.824187879515113e-06, 8.194968087835754e-04, 3.404083750893266e-02, 3.444787631795143e-02, -9.220741405483691e-01, -7.646010509179217e+00, 2.680852008896903e+01, -8.279500986609062e+00, -5.406633049312270e+00, -8.355254797178514e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_tpsslyp1w_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_tpsslyp1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.221199117803529e-06, -9.425981672655867e-06, -9.713175588764410e-06, -1.010512557829190e-05, -1.060575220206694e-05, -1.113007261292009e-05, -1.125975723685456e-05, -9.474170959941124e-06, -1.665877181252997e-06, 1.069541321191376e-05, -5.429414616049636e-05, -1.930875863023564e-04, -4.382209538217766e-02, -2.119967830170675e-01, -4.543233789702057e-02, -6.317518081265920e-02, -3.691545967659245e-01, 4.102342735328608e-04, 1.005799525729769e-05, 2.363182222986632e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
