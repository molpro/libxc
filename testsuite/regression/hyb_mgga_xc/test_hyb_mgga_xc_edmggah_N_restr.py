
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_edmggah_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.621962886393632e+00, -2.630133609785519e+00, -2.633926814451787e+00, -2.635276500060570e+00, -2.621697499253992e+00, -2.550096430830505e+00, -2.374435733367382e+00, -2.093334146666397e+00, -1.741879778027526e+00, -1.369603499249165e+00, -9.974423819702641e-01, -5.907800915421275e-01, -4.501187812326762e-01, -3.944426183362932e-01, -3.092830510138685e-01, -2.214208969565271e-01, -1.452117498787026e-01, -8.833451217307177e-02, -5.420070016131515e-02, -3.602773850087222e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_edmggah_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.776340272505388e+00, -3.838704051689467e+00, -3.947237393765981e+00, -4.080638110332555e+00, -4.106203316072046e+00, -3.844426777160308e+00, -3.351109832963177e+00, -2.747059409701996e+00, -2.070821437389570e+00, -1.436802342556740e+00, -9.639372673638565e-01, -7.435806170868658e-01, -6.799892073834141e-01, -5.395786351376122e-01, -3.537529864172483e-01, -2.185318398968020e-01, -1.270379759582381e-01, -5.631318421327496e-02, -2.613831234730593e-02, -1.380227994426253e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_edmggah_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.512679697361024e-07, 2.360228025141720e-08, -3.372712007310345e-07, -1.285989486132668e-06, -3.302111162622065e-06, -6.319752582116268e-06, -1.064475570475875e-05, -2.064924579481088e-05, -5.055660718498755e-05, -1.449537754094697e-04, -5.027981317239468e-04, -3.507663730703144e-03, -5.100819010334687e-03, -1.358325541393159e-02, -4.858869590802095e-02, -1.473069795627004e-01, -1.540735232398273e+00, -9.983614715591914e+01, -8.688595764220285e+03, -4.821794938213935e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_edmggah_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.079227048491279e-05, -1.115556909236167e-04, -2.303888235123200e-04, -4.864867729111619e-04, -9.024051823415778e-04, -1.286178979483511e-03, -1.511945807082797e-03, -1.781787253898368e-03, -2.188597388137469e-03, -2.614637560599720e-03, -3.451173997074226e-03, -7.288288176687741e-03, -7.746874914825025e-03, -1.049544855703064e-02, -1.360109679027144e-02, -1.360093749214418e-02, -1.014600689892024e-02, -6.543062357517164e-03, -4.963205638699153e-03, -3.723194667141895e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_edmggah_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.276474181783474e-05, 1.594050451861118e-04, 6.183673635249336e-04, 1.617657887289216e-03, 3.241772023252042e-03, 4.712051962287652e-03, 5.502969873860492e-03, 6.373107608572770e-03, 7.569336453917044e-03, 8.284842674310764e-03, 9.399234273853984e-03, 2.208883512216947e-02, 2.246216356936096e-02, 3.071879742393253e-02, 3.738751163480886e-02, 2.999273382351548e-02, 2.349638577195603e-02, 2.589244541873136e-02, 1.985282255479653e-02, 1.489277866856758e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_edmggah_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.383883470813722e-03, -1.206104435762415e-02, -1.612193774462574e-02, -2.034521655894594e-02, -2.017582616000260e-02, -1.747351582912733e-02, -2.217485214566756e-02, -3.520574203757443e-02, -6.343879518722009e-02, -9.512948789844758e-02, -1.185066348472704e-01, -4.807663413382571e-01, -6.689962779093360e-01, -9.371938537093450e-01, -2.175251830929424e+00, 5.651725183595406e-01, 1.386044967602445e+01, 1.196473077180097e+01, 1.284278240549132e+04, 9.171976243706768e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_edmggah_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.735283057138560e-09, -6.442517792256912e-09, -1.312027983614410e-08, -2.510808773923041e-08, -1.972642609337341e-08, 6.375678121984602e-08, 2.312501152470094e-07, 7.354543357175302e-07, 2.976621933418207e-06, 2.551013251640880e-06, -2.773390012622610e-04, 7.245211720257516e-03, -1.674158538863066e-03, 8.288151771887139e-02, 3.106480705930986e-01, -3.507754036237141e+01, -2.465648385027594e+03, -8.823308044626027e+04, 1.213608775170884e+09, 1.199412176385830e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_edmggah_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.294414768133345e-07, -1.675240536177406e-06, -4.206273658758166e-06, -8.766766677521330e-06, -1.023252290603205e-05, -1.982563949324891e-07, 8.948981390494964e-06, 1.635667235251710e-05, 1.616170409079378e-05, -1.728749454741650e-04, -1.304822574110718e-03, 4.196518471648820e-03, -7.719698584789650e-03, 1.708349466032617e-02, -2.330257706539634e-02, -1.030903160600955e+00, -1.113035509290336e+01, -2.136585891893655e+02, -1.668393912269576e+04, -8.717452395251840e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_edmggah_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.491929374331102e-06, 7.776310847139835e-06, 1.806434818760104e-05, 3.658594038932869e-05, 4.296275643839596e-05, 3.875490954890634e-06, -3.021824050288747e-05, -5.250452258340817e-05, -2.267400301632518e-05, 9.001978978781035e-04, 6.639862350935046e-03, -1.141619108079073e-02, 4.013962975423731e-02, -4.710730867388759e-02, 1.706077958763638e-01, 4.316584795876632e+00, 3.682676183128844e+01, 8.346982532776201e+02, 6.673575649077944e+04, 3.486980958100736e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_edmggah_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.439210597473113e-15, -6.081321756927028e-15, -2.742834580425116e-14, -1.194366216562568e-13, -3.821981313879810e-13, -5.151846296428307e-13, 2.495450172693906e-13, 3.650700882101052e-12, 1.799234737245899e-10, 1.263724531438614e-08, 1.616253993913553e-06, 3.328180572402693e-05, -1.667931581284542e-03, 2.348901258380442e-03, 8.291538855393125e-01, 2.894435535347636e+02, 3.674730167215205e+05, 7.142177950013309e+09, 7.412054916913031e+15, 2.176449762464793e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_edmggah_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.154868868811796e-13, -2.048818832792315e-12, -8.462649336805443e-12, -3.247844542899141e-11, -8.670754565768313e-11, -9.015287791217061e-11, 3.012285523061389e-11, 2.594661732620400e-10, 6.031631982079071e-09, 1.489862403305706e-07, 5.193263731758309e-06, 4.122502896499950e-05, -1.371621257012791e-03, 1.003410240880622e-03, 1.111040052503026e-01, 6.738981350840302e+00, 7.217532916090486e+02, 4.597437516663909e+05, 4.234004407186459e+09, 1.680566314566824e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_edmggah_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.061947547524718e-12, 8.195275331169260e-12, 3.385059734722177e-11, 1.299137817159656e-10, 3.468301826307325e-10, 3.606115116486824e-10, -1.204914209224556e-10, -1.037864693048160e-09, -2.412652792831628e-08, -5.959449613222825e-07, -2.077305492703324e-05, -1.649001158599980e-04, 5.486485028051165e-03, -4.013640963522488e-03, -4.444160210012105e-01, -2.695592540336121e+01, -2.887013166436194e+03, -1.838975006665564e+06, -1.693601762874583e+10, -6.722265258267297e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_edmggah_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.846336672430000e-10, -6.902543192724597e-10, -2.611037293639258e-09, -8.831875875724872e-09, -1.967094513695372e-08, -1.577597802458011e-08, 3.636163194815363e-09, 1.844103289790792e-08, 2.022003222488196e-07, 1.756466639337117e-06, 1.668672639891943e-05, 5.106402661133666e-05, -1.127950866689897e-03, 4.286396066722340e-04, 1.488758624658704e-02, 1.569006083996925e-01, 1.417594735515689e+00, 2.959381839483490e+01, 2.418599635462563e+03, 1.297665209813179e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_edmggah_N_restr_1_v2lapltau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapltau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapltau"])
    tgt = out["v2lapltau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.385346689719999e-10, 2.761017277089839e-09, 1.044414917455703e-08, 3.532750350289949e-08, 7.868378054781488e-08, 6.310391209832045e-08, -1.454465277926145e-08, -7.376413159163167e-08, -8.088012889952784e-07, -7.025866557348468e-06, -6.674690559567774e-05, -2.042561064453466e-04, 4.511803466759588e-03, -1.714558426688936e-03, -5.955034498634817e-02, -6.276024335987700e-01, -5.670378942062757e+00, -1.183752735793396e+02, -9.674398541850253e+03, -5.190660839252714e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_edmggah_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_edmggah", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.954138675888000e-09, -1.104406910835935e-08, -4.177659669822813e-08, -1.413100140115980e-07, -3.147351221912595e-07, -2.524156483932818e-07, 5.817861111704581e-08, 2.950565263665267e-07, 3.235205155981114e-06, 2.810346622939387e-05, 2.669876223827110e-04, 8.170244257813866e-04, -1.804721386703835e-02, 6.858233706755743e-03, 2.382013799453927e-01, 2.510409734395080e+00, 2.268151576825103e+01, 4.735010943173585e+02, 3.869759416740101e+04, 2.076264335701086e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
