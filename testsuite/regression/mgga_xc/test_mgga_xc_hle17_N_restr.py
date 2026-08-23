
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_xc_hle17_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_hle17", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.923205228004223e+00, -5.803683887556267e+00, -5.636155589643841e+00, -5.403989682462502e+00, -5.087455310942717e+00, -4.665896335791686e+00, -4.123140838547586e+00, -3.458241361937195e+00, -2.704440538322021e+00, -1.952037019916346e+00, -1.282698078757289e+00, -8.332791530955831e-01, -7.267434102407281e-01, -6.184372638886864e-01, -4.374071770483630e-01, -2.750948636074543e-01, -1.499409597746219e-01, -5.234076989309122e-02, -1.096180171380500e-02, -1.212702133699856e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_xc_hle17_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_hle17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.273424802405486e+00, -7.135061538670517e+00, -6.940966268206233e+00, -6.671581711072877e+00, -6.303221297034156e+00, -5.809549597370223e+00, -5.164622887447112e+00, -4.345489522629240e+00, -3.331851033099062e+00, -2.170800086524828e+00, -1.275608294509321e+00, -1.082481292516162e+00, -9.512014505648005e-01, -7.678850461832060e-01, -5.212652846467518e-01, -2.534897311825345e-01, -1.645184161906931e-01, -6.812270070646866e-02, -1.459933196543609e-02, -1.616912853708088e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_hle17_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_hle17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.782432518632436e-05, -1.835557998478400e-05, -1.913548320641106e-05, -2.028847273596302e-05, -2.200836610483713e-05, -2.460936697601710e-05, -2.869365664185201e-05, -3.626498257407003e-05, -6.089797368226451e-05, -2.168661243751793e-04, -1.329168346092805e-03, -1.577076940488346e-03, -1.479544177775710e-02, -4.668178787724625e-02, -8.952817420433906e-02, -6.365152592189935e-01, -2.410345457487415e+00, -3.755148702173507e+00, -4.466601914484549e+00, -4.931636546154897e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_hle17_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_hle17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.551685260745813e-02, 2.471940677586952e-02, 2.360170729408342e-02, 2.205286572475313e-02, 1.994255673733703e-02, 1.714219989682282e-02, 1.358976152323828e-02, 9.456564655700156e-03, 5.460226847556942e-03, 2.879748582790173e-03, 2.089887908744219e-03, -2.594811430473962e-04, 1.130684425439572e-02, 4.312126644472278e-02, 2.236856811206057e-02, 4.458268588562757e-03, 1.707989065849394e-04, 1.771518445614911e-06, 1.811223546126217e-09, 5.267189547167794e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_hle17_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_hle17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.931118472709948e-03, -6.049646511958473e-03, -6.230172234809383e-03, -6.518479085770699e-03, -7.023761474161327e-03, -8.074470385359444e-03, -1.091626285848317e-02, -2.126575826866555e-02, -6.711719124281325e-02, -2.328459397360139e-01, -5.245447498161905e-01, -5.626948001876827e-01, -8.643250507023816e-01, -9.829444840781960e-01, -3.866224741590343e+00, -6.299974854321579e+00, 5.713046541120433e+01, -5.035416712384493e+02, -1.680898453974010e+04, -1.395767764849296e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_hle17_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_hle17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.609043205081842e-07, -1.821878062844769e-07, -2.175043149339060e-07, -2.797127243369103e-07, -3.986715754974312e-07, -6.523036406655454e-07, -1.268821115088060e-06, -2.937736422141071e-06, -6.569417177112964e-06, 6.778296545269638e-06, 2.847174625380568e-04, 8.902913955565148e-03, 3.019792276766717e-02, -2.238878618268768e-01, -4.623308063020897e-01, -1.887497388596358e+01, -7.684908380511197e+03, -4.555446829722955e+05, -6.247109993118538e+07, -5.109339053848691e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_hle17_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_hle17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.828035519150646e-04, 1.950041931850954e-04, 2.137777641455909e-04, 2.434622258211735e-04, 2.921395855290484e-04, 3.757454469180294e-04, 5.271571647618731e-04, 8.146374778884904e-04, 1.373686764407206e-03, 2.484771137516311e-03, 4.963751838203604e-03, -9.922738113204257e-03, 1.311964446060906e-02, 2.494292915374915e-01, 1.160528708161572e+00, 1.973785082083778e+00, 5.945560770353373e-01, 2.445717143931791e-01, 2.896656490927347e-02, 6.330027322481928e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_hle17_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_hle17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.114628777886407e-12, 2.594873052061134e-12, 3.473571383498080e-12, 5.255030781737213e-12, 9.427736790044858e-12, 2.137395353631708e-11, 6.631095871837043e-11, 3.077029365277948e-10, 2.321345199690566e-09, 3.616331228072897e-08, 2.859591870883969e-06, -1.430582917148816e-03, -3.300166036860854e-02, 1.624569600230528e-01, 3.704334660926635e+00, 5.519823740895392e+02, 7.382436014018408e+05, 1.376689625955065e+09, 2.268558833682720e+13, 1.440397883466417e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_hle17_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_hle17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.330295774443862e-09, 2.426938386859105e-09, 2.548803293080193e-09, 2.668637106242667e-09, 2.645752674748911e-09, 1.848282352640958e-09, -2.725893329847079e-09, -2.748690746483362e-08, -1.802447299633087e-07, -1.256603606152263e-06, -8.301808799952426e-06, 1.028738898922260e-03, 4.192218628964847e-02, 4.210623175791729e-02, -1.077371026751676e+00, -8.423254372470620e+00, 3.855990487910723e+01, -1.421821296366184e+00, 5.018934563594071e-01, 9.605010287545914e-01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_xc_hle17_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_hle17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.089430006711151e-05, -1.112571030416024e-05, -1.144858681391865e-05, -1.188530307098698e-05, -1.243314454618681e-05, -1.297841937081203e-05, -1.300606024180782e-05, -1.071013924030797e-05, -1.377490640687834e-06, 1.233461418404317e-05, -7.198112152595552e-05, -2.400418629061986e-04, -5.375897993130785e-02, -2.506605301168236e-01, -8.186846679093776e-02, -3.798963580843998e-01, -9.699504937972564e-01, -2.380306681367900e-01, -3.046848475285293e-02, -7.003654665866934e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
