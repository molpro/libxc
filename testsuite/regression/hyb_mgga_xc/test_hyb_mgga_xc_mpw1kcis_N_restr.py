
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_mpw1kcis_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1kcis", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.724710179535507e+00, -3.654789702986291e+00, -3.556870326840579e+00, -3.421344963658898e+00, -3.236919933938369e+00, -2.991976589562958e+00, -2.677765795211832e+00, -2.294097400810310e+00, -1.856656675032916e+00, -1.398855266307268e+00, -9.480631231641418e-01, -6.145586855624858e-01, -5.295419814545569e-01, -4.367259093299913e-01, -3.197414541138762e-01, -2.080314296740585e-01, -1.190591061240684e-01, -3.104765571363415e-02, -6.204541201123766e-04, -1.909180935337185e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_mpw1kcis_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1kcis", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.673454507943444e+00, -4.576199698158230e+00, -4.439879636837749e+00, -4.250959632767433e+00, -3.993379713538843e+00, -3.650316234991756e+00, -3.208530158998716e+00, -2.666784725836949e+00, -2.049905798020137e+00, -1.429693976287548e+00, -9.393462094913386e-01, -7.587123091579636e-01, -6.811367776676335e-01, -5.349680956199895e-01, -3.570399014543357e-01, -2.015374734591570e-01, -1.158651272209200e-01, -8.048611019072280e-02, -2.290163673417923e-03, -7.059557380368283e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpw1kcis_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1kcis", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.462148035394597e-06, -2.679583764716346e-06, -3.023451527928756e-06, -3.589829895941115e-06, -4.577938805602447e-06, -6.446912039880743e-06, -1.040241367603394e-05, -2.016528319060275e-05, -4.974636602733762e-05, -1.665522474806495e-04, -8.261326651507148e-04, -3.606904531750732e-03, -2.161057815144845e-03, -8.971742492951627e-03, -4.907892563077577e-02, -3.621464098762571e-01, -2.708845041966727e+00, 8.917584885885088e+01, 4.049037373588367e+02, 1.021702308159757e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpw1kcis_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1kcis", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.212282073809705e-03, -1.193879987402960e-03, -1.167587764549651e-03, -1.130100786370784e-03, -1.076801465368222e-03, -1.001371110858054e-03, -8.957084035889734e-04, -7.514884474761306e-04, -5.670819389633522e-04, -3.667093138650232e-04, -2.392896474372746e-04, -3.792567337109326e-04, -3.116279924917580e-03, -9.069428552140622e-03, -7.607986839807014e-03, -3.996328657563519e-03, -1.338184407363444e-03, -2.179104887217504e-04, -1.169362396199223e-05, -1.639250050361012e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpw1kcis_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.046868130304829e-02, -1.094053728507473e-02, -1.165587058233989e-02, -1.276527540204505e-02, -1.454244651373513e-02, -1.752225157268650e-02, -2.284379958421453e-02, -3.316660097451960e-02, -5.511558660331996e-02, -1.044125837988547e-01, -2.369264884056863e-01, -4.867924587045147e-01, -5.994024516011082e-01, -1.059690995300377e+00, -2.426651170892635e+00, -6.112259823026983e+00, 6.695799173248149e+01, -1.499617250032893e+03, -2.146585667049843e+04, -4.913242210997560e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpw1kcis_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.375398773519225e-08, 2.691382221268211e-08, 3.218701119095309e-08, 4.157066609889844e-08, 5.986442292330700e-08, 1.004267713842529e-07, 2.079817336840224e-07, 5.708700743668702e-07, 2.221531826822634e-06, 1.232235724997675e-05, 1.609170937219033e-04, 9.106931451145120e-03, 3.654583767552141e-02, 1.344395094809879e-01, 1.008085659775436e+00, 9.917101698389287e+00, -6.714328534680950e+03, 1.604512569198704e+06, 5.191362775411881e+09, 9.668021894265891e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpw1kcis_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.083777918948022e-06, -7.518214679726399e-06, -8.184180415644833e-06, -9.232227692889038e-06, -1.094206817765137e-05, -1.386954538192681e-05, -1.920474588389911e-05, -2.970842813374442e-05, -5.239509300724296e-05, -1.073675378593708e-04, -2.674615987251520e-04, -5.907755294574620e-04, -4.757605187253825e-03, -4.338019459660556e-02, -1.646790717508913e-01, -6.518148184081476e-01, -3.006369529518329e+00, -1.748812828687980e+01, -1.086054516865912e+02, -1.131666376155758e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpw1kcis_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.361930064669054e-14, -2.488176827653462e-14, -2.554598809547948e-14, -2.200770908143168e-14, 3.395832193628884e-15, 1.527351035110317e-13, 1.206950625960524e-12, 1.224222946165513e-11, 2.260374416892603e-10, 1.018618008928137e-08, 1.380286149664437e-06, -8.650285354051238e-05, -7.046003962783137e-03, -1.730127447767060e-02, 7.884159598288942e-02, 1.681341321162600e+02, 6.976393392384972e+05, -1.204215088063666e+10, -1.937852306622504e+15, -2.848861141909338e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpw1kcis_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.195801757431016e-10, -1.321663755215496e-10, -1.525507689573963e-10, -1.872928619950413e-10, -2.509485319067628e-10, -3.801134854139625e-10, -6.825316793634439e-10, -1.547251503435866e-09, -4.820644557003536e-09, -2.384433120639927e-08, -3.541907137248054e-07, -8.718779995627508e-05, -6.006949481289279e-03, -2.722259861867297e-02, -1.382869256950811e-01, -1.538953189046757e+00, -4.691442157935040e+01, -1.406704655084364e+03, -1.748679421087998e+05, -1.366831165592721e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpw1kcis_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.507643719897518e-07, 5.775776095695653e-07, 6.182455440861939e-07, 6.812795692211949e-07, 7.819215737231715e-07, 9.491108554322610e-07, 1.241495834828726e-06, 1.786651428694649e-06, 2.887141788975661e-06, 5.430008120666942e-06, 1.560821128467996e-05, 1.778302061044852e-04, 1.006116285130082e-02, 8.272610242354729e-02, 2.348568853762032e-01, 7.809648652625077e-01, 3.500963708325957e+00, 1.967724709848474e+01, 1.312020080542852e+02, 1.453120585148711e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
