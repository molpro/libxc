
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_r2scan01_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan01", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.884473752458990e+00, -4.785582458667570e+00, -4.646969961181638e+00, -4.454867812654975e+00, -4.192911840759885e+00, -3.843850522324808e+00, -3.393661151855854e+00, -2.838974966970151e+00, -2.196912958152660e+00, -1.504517007136077e+00, -8.351011095813425e-01, -5.659440644744101e-01, -5.760713063789923e-01, -4.929445009470202e-01, -3.331262023619836e-01, -1.759733937866353e-01, -6.719459565678487e-02, -1.724229564855127e-02, -2.306859418304265e-03, -1.105138308053298e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_r2scan01_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan01", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.404242372041554e+00, -6.271241201737704e+00, -6.084784221796156e+00, -5.826290048188460e+00, -5.473581416314275e+00, -5.003029090604786e+00, -4.394818170447075e+00, -3.642480526942125e+00, -2.762250139071249e+00, -1.773536843401016e+00, -1.121465385519208e+00, -7.855961838368654e-01, -8.601066018508510e-01, -6.625119067552823e-01, -4.122760600358702e-01, -1.681390814089443e-01, -5.366943535534476e-02, -1.905176536188074e-02, -1.045954221040718e-03, 2.781316828106514e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan01_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan01", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.323293758204874e-06, -3.586428806220331e-06, -4.001138761642217e-06, -4.681903256789605e-06, -5.867813774608057e-06, -8.120999103432396e-06, -1.297515744253214e-05, -2.554529132831068e-05, -6.996191146190979e-05, -3.696551321963908e-04, -7.736354708435717e-04, -5.511516081341244e-03, -2.506151403725830e-02, -4.166167643679033e-02, -1.677604655942024e-01, -1.402961935800090e+00, -8.849170209609650e+00, -4.447832401784903e+01, -1.965219448022055e+03, -2.630301114673964e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan01_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan01", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.914374886557151e-03, 4.993544307200884e-03, 5.109323654607048e-03, 5.280463724047539e-03, 5.538153288133517e-03, 5.937719797371117e-03, 6.581097354701849e-03, 7.674202531789589e-03, 9.920985150789010e-03, 1.796664215225213e-02, 9.382938674426312e-03, 8.684924828081956e-03, 6.350929642946471e-02, 6.861152526813362e-02, 9.068023988309003e-02, 1.334321030960771e-01, 7.292744782465678e-02, 1.377634337697205e-02, 4.987759185666235e-03, 8.404170448552437e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan01_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.308745050800591e-02, -1.364838008285227e-02, -1.449959571797530e-02, -1.582288302974367e-02, -1.795155077402787e-02, -2.153193326654707e-02, -2.785544583524554e-02, -3.964146873898897e-02, -6.306633997274795e-02, -1.711544590809674e-01, -3.221192985902510e-01, -7.548553520010627e-01, -1.046669993382641e+00, -1.476242393179013e+00, -4.070504203468920e+00, -3.666669223114421e+01, -4.525734498826282e+02, -9.986086855206660e+03, -7.214815289756813e+05, -8.804547839022315e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan01_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.452351186991238e-09, 9.226873492362209e-09, 1.048177178809809e-08, 1.263282738469322e-08, 1.654828745962591e-08, 2.327300261567236e-08, 2.228100916227068e-08, -1.648427553312035e-07, -3.586973976708876e-06, -3.425387148541554e-05, 1.220541706593932e-04, -1.962325972535283e-02, 8.326169115512087e-02, 1.839927552586439e-01, 1.188059889437701e+00, 3.446401130575939e+02, 7.555733909840674e+04, 5.945757727186792e+07, 5.229170228610490e+11, 4.993329858888046e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan01_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.263494019631539e-06, 1.055011756592165e-05, 1.260912828693479e-05, 1.606571069523707e-05, 2.236236416378127e-05, 3.577446683979912e-05, 7.303083835261943e-05, 2.116484219040523e-04, 9.360622733304341e-04, 4.084637378388235e-03, 1.371034913104325e-03, 5.023198924863234e-02, 4.989210403803760e-02, -3.092959474284260e-02, 4.706066315183717e-01, -2.218683497475441e+01, -5.243063539509385e+02, -1.447093216033410e+04, -1.153984753030001e+06, -1.518305355209087e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan01_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.393935192541690e-13, 4.271831518879704e-13, 5.929441659276528e-13, 9.453800326008645e-13, 1.837237263331815e-12, 4.776159586115809e-12, 1.935323556144869e-11, 1.508748496528759e-10, 2.974284882774285e-09, 1.431040479448657e-07, -2.130745759264419e-06, 1.748744207049880e-03, 9.259953054884081e-04, 1.147447665673901e-01, 5.960249013072022e+00, -4.261615010522997e+03, -1.419729062272711e+07, -3.690761888063311e+11, -3.831576749294805e+17, -2.842538119016181e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan01_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.744487837909727e-10, -4.453188015827859e-10, -5.703302591164017e-10, -8.116148252291432e-10, -1.343557334790880e-09, -2.778875301848546e-09, -8.050305080741009e-09, -3.823354798855290e-08, -3.691864607453036e-07, -6.225747510333406e-06, 4.149777608307453e-05, 8.446876567378650e-04, -1.786605142861349e-03, -1.360487909861449e-01, -2.590416964493125e+00, 4.176120292499142e+02, 1.124479658620171e+05, 9.257115109724207e+07, 8.590343284889895e+11, 8.769824760678778e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan01_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.024377449396931e-07, 4.530412882036101e-07, 5.371028753318564e-07, 6.859496490838077e-07, 9.751377781306769e-07, 1.618477420750310e-06, 3.363385803102348e-06, 9.714876075501381e-06, 4.589405534207442e-05, 2.715630215275142e-04, -5.941191472303380e-04, -5.700513492052657e-03, -3.845896273292003e-02, 1.695240555896113e-01, 1.133835485075287e+00, -4.069134464131768e+01, -8.935059888398536e+02, -2.332549819187888e+04, -1.929443564106035e+06, -2.707185701375933e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
