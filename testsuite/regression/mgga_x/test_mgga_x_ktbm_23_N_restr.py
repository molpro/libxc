
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_23_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_23", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.234764987343704e+00, -5.133990886423085e+00, -4.992577111184279e+00, -4.796198378331320e+00, -4.527401215966981e+00, -4.166479146219047e+00, -3.693070133160496e+00, -3.086304859353639e+00, -2.323876078997686e+00, -1.455100846345477e+00, -7.942839000537634e-01, -5.476640271824352e-01, -5.805992922603391e-01, -5.058892357371972e-01, -3.287853129125998e-01, -1.581422474280558e-01, -6.282114600726645e-02, -1.959853209376709e-02, -4.046828962971507e-03, -4.476026696193672e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_23_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_23", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.289132279356059e+00, -6.151065844646793e+00, -5.958098177091056e+00, -5.691970520404839e+00, -5.332266987217031e+00, -4.861129330554624e+00, -4.274945394351557e+00, -3.605116454347843e+00, -2.902069810727296e+00, -2.028189693222390e+00, -1.115900163747420e+00, -7.987999922576005e-01, -8.778988873908414e-01, -6.898526750507288e-01, -4.590830661852772e-01, -2.190347991292853e-01, -8.314171013454404e-02, -2.565227635847820e-02, -5.280131338666788e-03, -5.831124805690518e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_23_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_23", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.340555762092943e-05, -1.450030433315343e-05, -1.622543057901297e-05, -1.905133008573060e-05, -2.393763360125297e-05, -3.303142726460919e-05, -5.162174318218371e-05, -9.354801514682743e-05, -1.901877811421985e-04, -3.618443203739418e-04, -6.299490374000940e-04, -3.718030932438976e-03, -2.708233208454195e-02, -6.803820821295055e-02, -1.736116243315150e-01, -3.510671554937570e-01, -6.875056437383916e-01, -3.584233568035401e+00, -8.481965686493295e+01, -7.720378727790033e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_23_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_23", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.364015775259963e-02, 1.404333480823437e-02, 1.464603707998272e-02, 1.556137954514535e-02, 1.698095141079350e-02, 1.923693633224776e-02, 2.287794230948998e-02, 2.843416077994911e-02, 3.356095963285456e-02, 2.585195163026147e-02, 9.222927415389999e-03, 1.001146185773911e-02, 7.035702405886686e-02, 1.159988711933169e-01, 1.271665866404033e-01, 5.032626462992430e-02, 7.339287622136786e-03, 9.691100112960666e-04, 1.883251137452112e-04, 2.343310596818833e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_23_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_23", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.782241331950840e-02, -1.864840826871220e-02, -1.988653271438924e-02, -2.176691482973817e-02, -2.465610042436380e-02, -2.908010038250980e-02, -3.540962774807203e-02, -4.198894356180248e-02, -4.831060294198489e-02, -1.394096296925687e-01, -3.533682934445104e-01, -8.831160092286291e-01, -9.316071212820592e-01, -1.209766850954288e+00, -2.737045340495501e+00, -9.046749272700945e+00, -3.313757508080106e+01, -3.082984574733301e+02, -7.206680135936851e+03, -5.913867878080810e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_23_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_23", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.703623881787897e-08, 1.111248052544228e-07, 1.348749903122329e-07, 1.776766601554499e-07, 2.622425229954198e-07, 4.508204144460697e-07, 9.338604623535428e-07, 2.247865663094992e-06, 3.326448038254508e-06, -4.016608732185142e-05, -5.409996105959278e-04, -8.128686009036414e-03, 2.011254171911557e-02, 1.261354259227926e-01, -1.228162055103339e+00, -3.637397956911294e+01, -1.747930018548970e+02, 2.199094700235547e+05, 7.533511763087062e+08, 4.957836600667178e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_23_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_23", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.144796386945595e-05, -7.935735814711702e-05, -9.221924621213868e-05, -1.142319652334886e-04, -1.546160677765895e-04, -2.355235158072967e-04, -4.124552689156096e-04, -7.866802307748925e-04, -9.156483357216823e-04, 3.261027133900393e-03, 1.021601739050122e-02, 4.830728352625818e-02, 6.601821473163312e-02, -1.205969097373960e-01, 1.089800225487957e+00, 6.529839597330271e+00, 5.777381352473072e+00, -4.792500433860657e+01, -1.656021995999524e+03, -1.504624251013166e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_23_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_23", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.934547797735424e-13, -2.454772353798010e-13, -3.453835548198916e-13, -5.630186464359070e-13, -1.130624206674898e-12, -3.041010851229164e-12, -1.220157565967938e-11, -8.210285207630855e-11, -9.769046603232050e-10, -1.819487586889933e-08, -6.336359861086102e-07, -5.461023452629472e-05, -2.807763760165038e-03, -4.178550567503046e-02, -1.510532328861205e+00, -1.634091719886306e+02, -1.452016969001649e+05, -1.723762013262010e+09, -6.218082028933578e+14, -3.171379150483175e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_23_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_23", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.077099017499840e-10, 6.142788439185828e-10, 8.075878050574386e-10, 1.195692947952935e-09, 2.096744185836488e-09, 4.668149627151839e-09, 1.444155172233193e-08, 6.828811837886196e-08, 5.003722041410550e-07, 4.378952360751731e-06, 4.092280039896701e-05, 1.464801987376861e-03, 2.997499165149824e-02, 2.402551615039903e-01, 3.900444492633010e+00, 7.309393241063114e+01, 2.505149387717671e+03, 6.046931391982578e+05, 1.852028187925908e+09, 1.304735615671422e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_23_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_23", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.070909111182788e-08, -5.321037754250993e-08, -9.677375320710953e-08, -1.907002078031042e-07, -4.241464793422372e-07, -1.123115333683646e-06, -3.777647155947060e-06, -1.701248218006792e-05, -9.517241632125315e-05, -4.086221609635882e-04, -8.643549904183245e-04, -6.268291162662855e-03, -8.113987028327359e-02, -4.132870957189408e-01, -3.637144405829901e+00, -1.475603251953756e+01, -3.485701998930712e+01, -2.009371160900420e+02, -5.158777807725641e+03, -4.998672203978772e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
