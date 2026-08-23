
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_br89_explicit_1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.417183422174964e+00, -3.405262629606258e+00, -3.383363271604608e+00, -3.343432488179680e+00, -3.272052398788000e+00, -3.148572373974090e+00, -2.945266112280751e+00, -2.635562662105984e+00, -2.218020113447412e+00, -1.730106124465534e+00, -1.201934420886941e+00, -6.593439584301012e-01, -5.181191033388840e-01, -4.617727670634315e-01, -3.695272520163385e-01, -2.578113810071611e-01, -1.686904382018824e-01, -1.105264729677640e-01, -7.476494961331996e-02, -4.911696628711788e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_br89_explicit_1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.779993504528806e+00, -4.842271341914586e+00, -4.905461241778837e+00, -4.945776838961953e+00, -4.909594377540580e+00, -4.695208705437155e+00, -4.177376919101862e+00, -3.379625272488803e+00, -2.535487045083050e+00, -1.777015111827220e+00, -1.175483020491594e+00, -9.115238454919935e-01, -7.869084461014312e-01, -6.310545977230017e-01, -3.996414626357777e-01, -2.295483719517789e-01, -1.165091886570038e-01, -6.321316215071750e-02, -2.750113472174381e-02, -2.354752125177531e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.476868006614250e-07, -3.191356502478957e-07, -7.020989041739479e-07, -1.581519573981188e-06, -3.657669060705749e-06, -8.589180248832428e-06, -1.960336183309462e-05, -4.133660824731785e-05, -8.806000602265362e-05, -2.407376827674316e-04, -1.075100124444584e-03, -9.326048733718355e-03, -9.283711720372021e-03, -3.852048943646003e-02, -1.144183278132944e-01, -5.584114832447393e-01, -5.817731018327076e+00, -1.384153666525771e+02, -1.359801579209080e+04, -5.907310195598455e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_1_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.289747674180919e-05, -1.075179305713483e-04, -2.166232286913413e-04, -4.300632123224406e-04, -8.297986856453062e-04, -1.503032648461299e-03, -2.366343503842355e-03, -2.937915732880019e-03, -2.952063661695090e-03, -2.838166180139194e-03, -3.454456109814589e-03, -1.155185606107245e-02, -7.634447649126161e-03, -1.645529093501704e-02, -1.533169501561286e-02, -1.300123815412389e-02, -1.142659820205439e-02, -8.909831202541832e-03, -7.767624422389183e-03, -4.561385562686754e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_1_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.115899069672368e-04, 4.300717222853932e-04, 8.664929147653652e-04, 1.720252849289762e-03, 3.319194742581225e-03, 6.012130593845195e-03, 9.465374015369420e-03, 1.175166293152008e-02, 1.180825464678036e-02, 1.135266472055678e-02, 1.381782443925835e-02, 4.620742424428979e-02, 3.053779059650464e-02, 6.582116374006818e-02, 6.132678006245146e-02, 5.200495261649557e-02, 4.570639280821756e-02, 3.563932481016733e-02, 3.107049768955673e-02, 1.824554225074702e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.251088649197919e-02, -1.465804784877061e-02, -1.757701559001283e-02, -2.126852940793834e-02, -2.513251244989539e-02, -2.781629631577214e-02, -3.265783218516042e-02, -5.292473855937236e-02, -8.163160782279907e-02, -1.322421685821916e-01, -2.756151917311302e-01, -6.627527721817317e-01, -1.050988008429718e+00, -1.448338919017964e+00, -2.886301725516311e+00, -6.136527173963608e+00, -2.249421504182079e+01, 3.692398361149680e+02, 1.464579077797230e+04, 1.990639087434825e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.509981147967596e-09, -3.295826966343962e-09, -7.225547676408805e-09, -1.536462940006626e-08, -2.681980922259939e-08, 1.963828590793574e-09, 3.430492242023661e-07, 1.450176774210404e-06, 3.076769618036528e-06, 9.153266883016873e-06, 1.165960645484440e-04, 1.951969224290287e-02, -1.145915635042300e-02, 2.353153286761299e-01, 5.834866379574787e-01, 2.032202432480343e+00, 3.193743383077959e+02, -5.225410670501582e+05, 5.864462978253401e+09, -5.588881810121358e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_1_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.362086136426000e-07, -1.748647075396810e-06, -3.633543926710594e-06, -7.341148597030064e-06, -1.339982583006077e-05, -1.683470738963447e-05, 2.203127873610712e-06, 2.039516141676167e-05, -7.297648304672254e-05, -3.735633336230851e-04, -1.775559805267426e-03, 5.526274486721266e-03, -2.799084500913267e-02, 2.348168455850089e-02, -1.506512866405378e-01, -1.069508130396670e+00, -1.100817929903808e+01, -3.104668303398061e+02, -2.384606151865380e+04, -1.224617119784399e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_1_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.344834454570400e-06, 6.994588301587240e-06, 1.453417570684237e-05, 2.936459438812026e-05, 5.359930332024306e-05, 6.733882955853787e-05, -8.812511494442848e-06, -8.158064566704667e-05, 2.919059321868901e-04, 1.494253334492341e-03, 7.102239221069703e-03, -2.210509794688506e-02, 1.119633800365307e-01, -9.392673823400358e-02, 6.026051465621510e-01, 4.278032521586681e+00, 4.403271719615230e+01, 1.241867321359224e+03, 9.538424607461521e+04, 4.898468479137595e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.722439939130366e-15, -6.153798576652271e-15, -2.367052490769095e-14, -1.000833517037154e-13, -4.669489692348772e-13, -2.227591836372838e-12, -7.048345857532607e-12, 3.098219124146374e-11, 8.199362385281751e-10, 2.058401812961035e-08, 1.952502355619658e-06, -1.606028437762274e-04, -4.015976029763532e-03, -1.290951275455142e-02, 2.082202808994232e+00, 3.028008442814273e+02, 4.067362192862354e+05, 1.029071609683258e+10, 1.085324319881548e+16, 2.952106749527046e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_1_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.169320901479174e-13, -2.073236529985336e-12, -7.303223947280863e-12, -2.721570345496618e-11, -1.059345814243152e-10, -3.898094067788792e-10, -8.508136295606760e-10, 2.201996509795889e-09, 2.748698397821258e-08, 2.426743642094060e-07, 6.273679574990476e-06, -1.989332231981785e-04, -3.302532401140370e-03, -5.514721939238655e-03, 2.790086084831132e-01, 7.049973017920934e+00, 7.988700985599962e+02, 6.624159267388054e+05, 6.199721946365390e+09, 2.279497209548281e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_1_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.467728360591670e-12, 8.292946119941343e-12, 2.921289578912345e-11, 1.088628138198647e-10, 4.237383256972608e-10, 1.559237627115517e-09, 3.403254518242704e-09, -8.807986039183555e-09, -1.099479359128503e-07, -9.706974568376239e-07, -2.509471829996190e-05, 7.957328927927141e-04, 1.321012960456148e-02, 2.205888775695462e-02, -1.116034433932453e+00, -2.819989207168373e+01, -3.195480394239985e+03, -2.649663706955221e+06, -2.479888778546156e+10, -9.117988838193124e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_1_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.209686359493266e-10, -6.984807279155308e-10, -2.253312093083603e-09, -7.400776472208824e-09, -2.403289498621870e-08, -6.821329254856778e-08, -1.027026549034328e-07, 1.565024433347406e-07, 9.214549287085243e-07, 2.860998599672055e-06, 2.015826270138427e-05, -2.464117469000519e-04, -2.715833007903732e-03, -2.355794416516450e-03, 3.738627345589119e-02, 1.641412845838018e-01, 1.569059759401799e+00, 4.263987616297072e+01, 3.541480782116778e+03, 1.760135377614940e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_1_N_restr_1_v2lapltau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapltau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapltau"])
    tgt = out["v2lapltau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.838745437973062e-10, 2.793922911662123e-09, 9.013248372334413e-09, 2.960310588883530e-08, 9.613157994487478e-08, 2.728531701942711e-07, 4.108106196137311e-07, -6.260097733389624e-07, -3.685819714834097e-06, -1.144399439868822e-05, -8.063305080553708e-05, 9.856469876002075e-04, 1.086333203161493e-02, 9.423177666065801e-03, -1.495450938235648e-01, -6.565651383352070e-01, -6.276239037607197e+00, -1.705595046518829e+02, -1.416592312846711e+04, -7.040541510459759e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_1_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.535498175189225e-09, -1.117569164664849e-08, -3.605299348933765e-08, -1.184124235553412e-07, -3.845263197794991e-07, -1.091412680777084e-06, -1.643242478454924e-06, 2.504039093355849e-06, 1.474327885933639e-05, 4.577597759475289e-05, 3.225322032221483e-04, -3.942587950400830e-03, -4.345332812645971e-02, -3.769271066426320e-02, 5.981803752942590e-01, 2.626260553340828e+00, 2.510495615042879e+01, 6.822380186075314e+02, 5.666369251386845e+04, 2.816216604183904e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
