
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_bmk_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_bmk", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.289794713556332e+00, -2.258087492879735e+00, -2.214031857031161e+00, -2.153567264911239e+00, -2.071620876323047e+00, -1.961033204883669e+00, -1.808094538541725e+00, -1.583863927201719e+00, -1.271515239674079e+00, -9.623872365926763e-01, -6.158719447762302e-01, -3.802106334896466e-01, -2.965403549338324e-01, -2.765090368557854e-01, -2.082559049885866e-01, -1.186206724297642e-01, -9.601084875678963e-02, -7.318166436875309e-02, -1.713885124384042e-02, -1.906315829779944e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_bmk_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_bmk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.022078677933691e+00, -1.967109036198573e+00, -1.894042460241931e+00, -1.802061728613474e+00, -1.698460951903264e+00, -1.610189669544545e+00, -1.593416262890666e+00, -1.661732419979266e+00, -1.472949053892586e+00, -9.387429234966115e-01, -8.755073455773057e-01, -4.057207192348726e-01, -2.697002527423861e-01, -2.756513317975691e-01, -2.102773840930484e-01, -1.793816361413049e-01, 7.633055488753065e-02, -7.270471515402709e-02, -2.257675183868065e-02, -2.541361342997920e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_bmk_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_bmk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.161510756207337e-05, -1.242047261442015e-05, -1.363884724933890e-05, -1.550361204601954e-05, -1.836355614476293e-05, -2.258828735326282e-05, -2.774951346811879e-05, -2.963619515464976e-05, -2.828328396566924e-05, -1.292198281124805e-04, -2.153768182139964e-04, -8.081767573868907e-03, -3.284959188757772e-02, -3.806747336313894e-02, -5.689035358653876e-02, -2.394800657761120e-01, -1.436035122224660e+01, -5.604899318173631e+01, -7.488595319502139e+01, -8.311436030497444e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_bmk_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_bmk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.257724907859481e-03, 1.051851504708346e-03, 7.761504178130437e-04, 4.348594267629931e-04, 9.248730850795591e-05, -2.612357476472779e-05, 5.422418409914093e-04, 1.694829918051399e-03, 4.496161808196475e-05, -6.107145686922330e-04, 4.250653190548078e-03, -4.450220406147075e-05, -1.484106626013509e-02, 5.514773762272591e-03, -4.356134774796061e-03, 4.500527383182569e-02, 5.775485928695779e-03, 2.132409858097902e-06, -3.872029774331428e-09, -8.335742982551660e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_bmk_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_bmk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.921904916001936e-03, -7.550999847516129e-03, -6.752963971139832e-03, -4.959400634479633e-03, -7.636423153828763e-04, 9.215385310198502e-03, 3.106674905971152e-02, 5.740294078341564e-02, -1.756613049676669e-02, -1.557640928421811e-03, 6.021571785349016e-01, -3.307649723517871e-01, 2.938544707855147e-01, 1.044317712007881e+00, -1.556607837572408e+00, -1.770118469304484e+01, 1.138450895170397e+02, 2.015069537865032e+03, -2.251527725304499e+04, -2.190086845740611e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_bmk_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_bmk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.466290142472891e-08, 9.974790701159584e-09, -4.739650384253546e-10, -2.619356955284169e-08, -9.747633862198809e-08, -3.237112031745386e-07, -1.137467535245505e-06, -4.023635105183252e-06, -7.389981731402279e-06, 9.849852823005486e-06, -1.052841872572574e-03, 4.798928319699647e-03, -5.835614192938966e-02, -4.453586882431181e-01, 3.110786667115596e-02, 1.011935347415605e+02, -8.609413007194031e+03, -6.240201037211424e+06, -1.043670563505383e+09, -8.610571158567701e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_bmk_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_bmk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.814111342730339e-05, 6.810661013438792e-05, 6.612415182559069e-05, 5.847559475827553e-05, 3.555104387978855e-05, -2.410919716905338e-05, -1.374438886568249e-04, -7.108428844241559e-05, 1.199259074597982e-03, -1.990201456483014e-03, -1.221404714595645e-02, 4.582137732929380e-03, -1.415467035162923e-01, -1.611817704200377e-01, 2.962194848930329e-01, -4.322155819486694e+00, 3.011108161911251e+01, 1.052105653584693e+00, -6.076034574299501e-02, -1.007083011022146e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_bmk_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_bmk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.493227367053478e-13, 1.207410229651049e-12, 1.702177659324178e-12, 2.774058530421679e-12, 5.528481810258523e-12, 1.445447865186741e-11, 5.336351752944883e-11, 2.872159147346718e-10, 1.957608961389925e-09, 1.263100900342238e-08, 1.384226963101925e-08, 1.327083598295489e-03, 2.504715620238679e-02, 2.075328010734638e-01, 2.258333214183371e+00, -8.706999324678798e+02, 1.940533679135485e+06, 1.929812498115720e+10, 3.793388039072906e+14, 2.427471933650490e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_bmk_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_bmk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.066889595176027e-10, -4.230341753573333e-10, -4.323120931892486e-10, -4.002309634660407e-10, -1.984914111641887e-10, 6.418482218652719e-10, 3.440533011672332e-09, 3.183304549936450e-09, -1.504154159713328e-07, -3.144946811383086e-07, 3.855495530687052e-05, -3.431078033868330e-04, 3.881348573896926e-02, 7.270643209015369e-02, -8.039107594886968e-01, 6.063025689437707e+01, -4.003700102518627e+02, -1.683536451504522e+03, -6.708592710684009e+02, -1.006218848130907e+02]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_mgga_x_bmk_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_bmk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.952242166606973e-07, -8.110856628635073e-07, -8.151068272809698e-07, -7.740722794944558e-07, -6.000985768970277e-07, -1.071034660441948e-07, 7.636342464083116e-07, -8.633735755810370e-09, -2.055007812681113e-07, 7.348405062765081e-05, -9.882316535041210e-05, -2.459697398445717e-05, 1.955566875386549e-02, -2.520382245094631e-02, 3.590185644333643e-01, -5.657211359388579e+00, -2.016752155941944e+01, -2.851739194602122e-01, 6.512702823611377e-02, 1.108379870340930e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
