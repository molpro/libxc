
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_x1b95_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_x1b95", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.082822962352683e+00, -3.025204060167599e+00, -2.944509964250603e+00, -2.832820106834039e+00, -2.680818952560080e+00, -2.478910392476953e+00, -2.219828625370031e+00, -1.903264228450179e+00, -1.541747723769813e+00, -1.162222679195452e+00, -7.885489820273336e-01, -5.342111801096969e-01, -4.416122040045243e-01, -3.629640726763160e-01, -2.659045988498567e-01, -1.720782820666632e-01, -1.001885236533950e-01, -5.098603935452321e-02, -3.132987314720145e-02, -2.172790914194782e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_x1b95_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_x1b95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.843600240402630e+00, -3.763967861131717e+00, -3.652359922774595e+00, -3.497710199821297e+00, -3.286902245593511e+00, -3.006227717903665e+00, -2.644970348677591e+00, -2.202297081561904e+00, -1.698462776886175e+00, -1.190376605478905e+00, -7.893343490198919e-01, -6.625942479965493e-01, -5.515472664587499e-01, -4.408021924858165e-01, -2.977639015239302e-01, -1.662252822243087e-01, -8.321636850510906e-02, -3.045538545697837e-02, -8.638158723890864e-03, -3.553775327608916e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_x1b95_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_x1b95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.560231133499455e-06, -2.758613886521126e-06, -3.070318660247010e-06, -3.579189733395005e-06, -4.456553672013103e-06, -6.091148008438724e-06, -9.487928637218920e-06, -1.770373044030387e-05, -4.211802533076320e-05, -1.371856567867721e-04, -6.486909778868034e-04, 2.596544232749281e-03, 1.101551231191036e-03, -8.230376878088856e-03, -4.203963844456106e-02, -3.145049079585683e-01, -3.367022736531758e+00, -8.448514577083635e+01, -9.021471839357693e+03, -5.373993047599953e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_x1b95_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_x1b95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.375567663333888e-04, -3.424569951505816e-04, -3.492532570038716e-04, -3.584443056041141e-04, -3.702743158825236e-04, -3.839209698517954e-04, -3.954169130397689e-04, -3.935947374396980e-04, -3.585826108127490e-04, -2.919286190495682e-04, -3.934739840274068e-04, -5.911249725741185e-03, -1.215099559354934e-02, -8.595759447999491e-03, -5.100653368791458e-03, -1.941883042677230e-03, -3.394174606475803e-04, -2.122505356273371e-05, -3.221485433594406e-07, -6.299510954859019e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_x1b95_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_x1b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.323159709275796e-03, -8.696400320297067e-03, -9.262368063614327e-03, -1.014045604753552e-02, -1.154795629511047e-02, -1.391043264600400e-02, -1.813745567663961e-02, -2.637041508254391e-02, -4.413003781752439e-02, -8.676104038366458e-02, -2.155670115069773e-01, -2.351886318597871e-01, -3.685994832375293e-01, -7.719203851748547e-01, -1.999432175005299e+00, -6.178159820702189e+00, 1.068608963515900e+01, -5.512406284010217e+02, 8.926423217987389e+03, 5.568341686818012e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_x1b95_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_x1b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.445832496711273e-08, 1.648191235736554e-08, 1.988716836388609e-08, 2.602043507519440e-08, 3.818823981954890e-08, 6.585383420617872e-08, 1.418557933051172e-07, 4.110748738177496e-07, 1.728806735877925e-06, 1.151087674754267e-05, 2.393287974051171e-04, 6.404198076362997e-03, -2.894686842576377e-03, 9.658239953049841e-02, 9.688902344855197e-01, 1.520393938235742e+01, -2.429238297956802e+03, 5.423762525409166e+05, -5.173409772960949e+09, -1.826076921205070e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_x1b95_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_x1b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.617578248211794e-06, -1.829183131956686e-06, -2.174872864687964e-06, -2.769351600943678e-06, -3.864806628696994e-06, -6.072754570443859e-06, -1.103528589734494e-05, -2.357149524392739e-05, -5.858087267398964e-05, -1.689407216062558e-04, -9.018020406182865e-04, -1.440910780837978e-02, -1.730638894015350e-02, -7.371400611027790e-02, -2.381614667286154e-01, -6.950994680341150e-01, -1.626510888596800e+00, -3.216408521515735e+00, -5.568582976990760e+00, -8.117935153904893e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_x1b95_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_x1b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.161815756704205e-14, 3.900041886221767e-14, 5.275485922875008e-14, 8.152220891875231e-14, 1.527673182124138e-13, 3.791321200138109e-13, 1.420486696777431e-12, 9.689895811385457e-12, 1.505562301189323e-10, 6.352882220507730e-09, 5.141484362453169e-07, -2.620096998330888e-03, -1.387839219019779e-02, -4.330645568828141e-02, -5.929148627845290e-01, 7.100147091365159e+01, 4.606706357483795e+05, 6.639781211663004e+09, 1.287449056231498e+16, 4.310155480906929e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_x1b95_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_x1b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.916050179873967e-11, 3.446096601149647e-11, 4.373770127880466e-11, 6.138564941131550e-11, 9.912267028079568e-11, 1.939545178257547e-10, 4.901359636795506e-10, 1.715978639403006e-09, 8.928588069670857e-09, 7.918849669045722e-08, 2.762267028323556e-06, 1.573286494359455e-03, 1.236868686480505e-02, 3.538576891525783e-02, 2.619793796742150e-01, 4.173191644341570e+00, 1.214262748700987e+02, 7.899879129525601e+03, 1.637581142200522e+06, 1.839943426341287e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_x1b95_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_x1b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
