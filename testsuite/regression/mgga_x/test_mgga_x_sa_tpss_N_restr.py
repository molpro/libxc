
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_sa_tpss_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sa_tpss", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.717200916352076e+00, -4.621785748086781e+00, -4.488056075660134e+00, -4.302750116400662e+00, -4.050147766632543e+00, -3.713823164600139e+00, -3.280990861570819e+00, -2.751106200230818e+00, -2.150883272106817e+00, -1.552201799533012e+00, -1.024903310073757e+00, -6.494605595246213e-01, -5.604882250752522e-01, -4.799802811001750e-01, -3.412878753208443e-01, -2.173028034399378e-01, -1.262230044894277e-01, -5.967883716014483e-02, -2.645686027490315e-02, -1.281278191224771e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_sa_tpss_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sa_tpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.757587872820806e+00, -5.647192395885972e+00, -5.492334170781874e+00, -5.277415204777204e+00, -4.983551419981254e+00, -4.589770513524680e+00, -4.075511012666493e+00, -3.423103999239250e+00, -2.620096792025254e+00, -1.718655991836828e+00, -9.856513377228160e-01, -8.304224781386824e-01, -7.280353309630495e-01, -5.847646327761763e-01, -3.950068626898482e-01, -2.004317894180997e-01, -2.038516007059681e-01, -2.499704998624014e-01, -2.808513287905158e-01, -3.238528245759944e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sa_tpss_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sa_tpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.515969008375061e-05, -1.563731123980852e-05, -1.634250559404116e-05, -1.739438671276313e-05, -1.898598181180220e-05, -2.144935175870732e-05, -2.545648478802850e-05, -3.309442075429770e-05, -5.603294226762959e-05, -1.737980473288045e-04, -1.095653928517952e-03, -2.647262670501758e-03, -1.571947686249442e-02, -4.237547326214807e-02, -8.058371947004936e-02, -3.920648690008253e-01, 1.352606991644720e+01, 1.171067641101605e+03, 1.896663874776192e+05, 1.782199478306530e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sa_tpss_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sa_tpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.150036251606884e-02, 2.085328438925917e-02, 1.994626583713593e-02, 1.868916976335548e-02, 1.697578870905329e-02, 1.470042399207164e-02, 1.180829487065604e-02, 8.420994157313302e-03, 5.026665434204442e-03, 2.119735039765125e-03, 9.582279501675281e-04, -2.207987966924692e-04, 9.171729941904048e-03, 3.439599757931008e-02, 1.580829646410590e-02, -1.097946677331580e-02, -1.263888797622860e-01, -3.045472767223985e-01, -4.336239340528186e-01, -5.504667097324065e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sa_tpss_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sa_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.198821025874921e-03, -5.334672599794222e-03, -5.544667660076860e-03, -5.885099321275268e-03, -6.485858881522562e-03, -7.713740599173519e-03, -1.086087298131811e-02, -2.147611732409500e-02, -6.458072963173674e-02, -1.823250793946229e-01, -4.279663493814043e-01, -4.409239170649075e-01, -6.937093074906160e-01, -7.405594305988337e-01, -2.726816400539390e+00, 4.038417609850858e+00, 7.523417163265324e+02, 6.012150865963723e+04, 1.503585260434059e+07, 2.556772235541579e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sa_tpss_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sa_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.154542890474202e-07, -1.304027216864298e-07, -1.550788707454895e-07, -1.981792762325341e-07, -2.794028753667224e-07, -4.478133319259422e-07, -8.321165475374023e-07, -1.681957650811973e-06, -1.427673273913556e-06, 1.276551230934192e-05, 4.337240058285657e-05, 6.828323820893648e-03, 2.821680790477465e-02, -2.031583765125303e-01, -7.490695217519010e-01, -9.363748025166950e+01, -1.096966418889138e+05, -3.395180315933864e+08, -1.061616870112265e+13, -1.420823182169411e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sa_tpss_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sa_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.279605286461921e-04, 1.361576239259488e-04, 1.486808137093969e-04, 1.682544336161536e-04, 1.997232668790060e-04, 2.518205154990047e-04, 3.390781571874506e-04, 4.741316600387025e-04, 6.090753619493958e-04, 1.398735984405999e-03, 6.513216334734160e-03, -7.938033395407733e-03, 1.097177577144635e-02, 2.190572538789224e-01, 9.657784136409561e-01, 5.261385507538771e+00, 6.140486447928192e+02, 7.669167784076445e+04, 2.271559418957375e+07, 4.245692522805269e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sa_tpss_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sa_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.318078208956211e-12, 1.617450403358168e-12, 2.163292979522183e-12, 3.262752270705137e-12, 5.805488878894479e-12, 1.289403030555834e-11, 3.795403715626571e-11, 1.509235065658794e-10, 6.149882279651087e-10, 1.283123161085460e-08, 3.791070418727014e-06, -8.517849995623299e-04, -2.310003384125753e-02, 1.534621569988511e-01, 3.412734502788890e+00, 8.105243648928860e+02, 1.473970538642951e+07, 1.904349103894230e+12, 7.494106576151120e+18, 7.896133051095625e+27]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sa_tpss_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sa_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.574600555652061e-09, 2.754350732629646e-09, 3.026240141679294e-09, 3.442249011835332e-09, 4.079960047126222e-09, 5.022214327746359e-09, 6.198294751931207e-09, 7.377246898001797e-09, 2.587717067839057e-08, -1.398373217455875e-07, -1.752441707868299e-05, 8.264107110715357e-04, 3.382598891368021e-02, 3.192699426431823e-02, -7.874320199304973e-01, -8.750823056870153e+00, -9.719594395038967e+04, -4.831180057662002e+08, -1.710686816476837e+13, -2.438752854706201e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sa_tpss_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sa_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.957026651768804e-06, -1.022929426191196e-05, -1.062475118537083e-05, -1.119895074538195e-05, -1.202847602162764e-05, -1.320900755854090e-05, -1.484956891939988e-05, -1.728116832846360e-05, -2.340283692678093e-05, -3.066601646340760e-05, -4.163446481601852e-06, -1.953195240586580e-04, -4.359148853637543e-02, -2.096351071763332e-01, -1.295195331019655e-01, -2.260926030129524e+00, 6.649042798139197e+02, 1.228141251865736e+05, 3.905285607246511e+07, 7.532196373761113e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
