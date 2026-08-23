
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_ksdt_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_ksdt", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.280322471687448e+00, -4.195532821190144e+00, -4.076687250444913e+00, -3.911985205958706e+00, -3.687412884082291e+00, -3.388237917562089e+00, -3.002640994112519e+00, -2.528460791459830e+00, -1.983407539778733e+00, -1.418922642936213e+00, -9.466545559533077e-01, -7.291889854904294e-01, -6.447429555203918e-01, -5.234593944234055e-01, -3.668994102396433e-01, -2.165035215557028e-01, -1.029483403350731e-01, -3.621196895353217e-02, -8.186460879533432e-03, -9.622987830705008e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_ksdt_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_ksdt", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.679434311142109e+00, -5.679391343405325e+00, -5.566561441560009e+00, -5.566471663324469e+00, -5.408374098484297e+00, -5.408185683570687e+00, -5.189196179183679e+00, -5.188798184169142e+00, -4.890447441042879e+00, -4.889598603285121e+00, -4.492687306908655e+00, -4.490850512550150e+00, -3.980580661701729e+00, -3.976517415074682e+00, -3.352219185500726e+00, -3.342921070437882e+00, -2.633668396230036e+00, -2.611275163142636e+00, -1.899687919620914e+00, -1.842041872771907e+00, -1.303956115430109e+00, -1.154594232169998e+00, -1.020157838086243e+00, -7.604328599790851e-01, -8.994292891508435e-01, -6.617784571091511e-01, -7.273740053035039e-01, -5.491825440299555e-01, -5.055958791880257e-01, -3.863101539414018e-01, -2.941496698087269e-01, -2.292137595956150e-01, -1.373191977298580e-01, -1.135746293367248e-01, -4.770138157997354e-02, -4.389254801169885e-02, -1.079748348569152e-02, -1.092959408584655e-02, -1.277372611658101e-03, -1.351164211476751e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_ksdt_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_ksdt", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.025769316732112e-02, -5.465089295927667e-04, -2.025800764457838e-02, -2.109521292017758e-02, -5.774018679685737e-04, -2.109591129957417e-02, -2.235914537690000e-02, -6.248749030087833e-04, -2.236074518364924e-02, -2.430682579567835e-02, -6.999626276364100e-04, -2.431065786044044e-02, -2.739912216942278e-02, -8.237504161265514e-04, -2.740891037059794e-02, -3.252249393192754e-02, -1.040310582721603e-03, -3.254991830418483e-02, -4.154087919510596e-02, -1.452799424446295e-03, -4.162865299399839e-02, -5.882360548671044e-02, -2.339794087714293e-03, -5.916368193043202e-02, -9.595801463315258e-02, -4.600952095701674e-03, -9.768568195653660e-02, -1.864742956276933e-01, -1.177932414467883e-02, -1.990271290229499e-01, -4.014976957417808e-01, -3.810167115509688e-02, -5.219768370056392e-01, -6.632078086470128e-01, -9.299910778815296e-02, -1.276373520925353e+00, -8.597583806682320e-01, -1.350051833846141e-01, -1.717266234808607e+00, -1.333852457182199e+00, -2.413942987557489e-01, -2.532816866080266e+00, -2.845152197185581e+00, -6.771294512140829e-01, -5.356471675829733e+00, -8.919563030280143e+00, -3.140823926670704e+00, -1.652837922814470e+01, -4.594855322849400e+01, -2.524284008747883e+01, -7.525463891064980e+01, -4.679199762677578e+02, -3.716391177082817e+02, -5.591976162562551e+02, -1.203939928062747e+04, -1.172939624354141e+04, -1.048835345872891e+04, -1.081939325745969e+06, -1.135754935785150e+06, -8.433476487476713e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
