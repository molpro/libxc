
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_vt84_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vt84", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.787771682650986e+00, -4.690740773697249e+00, -4.554698259341425e+00, -4.366082571651649e+00, -4.108736494036288e+00, -3.765570620839315e+00, -3.322714926094961e+00, -2.777691023220822e+00, -2.153915424458828e+00, -1.522327049230802e+00, -9.757546339321100e-01, -6.457397260218763e-01, -5.583476730057969e-01, -4.744923529082995e-01, -3.356205275850354e-01, -2.061452920802504e-01, -1.190907688909070e-01, -3.786712840522471e-02, -4.538723383915341e-03, -2.953402496880367e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_vt84_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vt84", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.645549217089707e+00, -5.536787854842314e+00, -5.384401415451490e+00, -5.173294435439636e+00, -4.885459079882763e+00, -4.501506365599125e+00, -4.003775028322888e+00, -3.379484732157636e+00, -2.619449102224818e+00, -1.743193102159513e+00, -1.022977469096744e+00, -8.393269460456561e-01, -7.333159954586005e-01, -5.801979443106994e-01, -3.942227989643100e-01, -1.898728964303051e-01, -1.109191719891159e-01, -8.113041320425569e-02, -6.830632838000481e-03, -4.490661615190431e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_vt84_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vt84", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.118895948822295e-05, -2.197573683548520e-05, -2.315006639763055e-05, -2.492896528854333e-05, -2.767822260609178e-05, -3.204387607658306e-05, -3.925488245966677e-05, -5.213316324886763e-05, -8.140966906292483e-05, -2.024148346456536e-04, -9.604727720542538e-04, -1.126821645086498e-03, -1.107554487672907e-02, -4.871505029358566e-02, -1.017878183950742e-01, -5.259190007295855e-01, -3.268672194317688e+00, 6.905136438935818e+01, 2.120966517646612e+02, 8.662224224992242e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_vt84_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vt84", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.018464591111670e-02, 2.946442252478594e-02, 2.845222205487821e-02, 2.704304994986125e-02, 2.510700423832816e-02, 2.249731513673734e-02, 1.908169177696995e-02, 1.483442455150458e-02, 1.005561895612938e-02, 5.667478998652623e-03, 2.596244743308153e-03, -6.635722182629387e-04, 7.433209702822698e-03, 4.597695737173996e-02, 3.397300881237262e-02, 9.027475344166301e-03, 2.694770826972415e-04, -2.209740315353330e-06, -1.258054389291807e-10, -1.143416809268666e-15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_vt84_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vt84", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.576570998726225e-03, -4.604978014976477e-03, -4.637942127306359e-03, -4.670220846029104e-03, -4.692819297863109e-03, -4.721087672674167e-03, -5.030039852565959e-03, -7.794470322639918e-03, -2.737967270530439e-02, -1.292318831769153e-01, -4.234247541754278e-01, -4.023406282137071e-01, -6.621778936792692e-01, -8.895760706238768e-01, -2.102594057783342e+00, -8.714552433349635e+00, 8.284534481679184e+01, 1.555222021816017e+03, -4.253219425139392e+03, -1.370091242433214e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_vt84_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vt84", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.317256093476982e-07, -1.501780132336374e-07, -1.810955638024471e-07, -2.363569932945014e-07, -3.444486625216395e-07, -5.835618136512419e-07, -1.204597939412785e-06, -3.148915961471251e-06, -1.015312078243541e-05, -2.944445743759155e-05, 3.003424629173631e-04, 2.096770945323938e-03, 8.029655486163393e-03, -4.842895284077278e-02, -1.409483715337691e+00, -6.185846994757912e+00, -8.294038218065823e+03, -5.397475954789024e+06, -1.012450078332142e+09, 2.814875148229474e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_vt84_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vt84", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.548772680275021e-04, 1.659590721462315e-04, 1.831136054580425e-04, 2.104812345763513e-04, 2.559704802605449e-04, 3.357654869311060e-04, 4.853169183737754e-04, 7.862985464245824e-04, 1.427440458239504e-03, 2.718836882646792e-03, 3.093852028174479e-03, -6.579886057836756e-03, 1.834961442903188e-02, 6.690159434280135e-02, 1.015763963880827e+00, 3.025433372638703e+00, 1.430628841373403e+00, -1.666189862370158e-01, -2.011775035357711e-03, -5.554853952658372e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_vt84_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vt84", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.771655287349452e-12, 2.192466958939423e-12, 2.968634639853059e-12, 4.559895731633793e-12, 8.345310215687092e-12, 1.942137446130292e-11, 6.244283759267295e-11, 3.059690884227051e-10, 2.533310080221775e-09, 3.956899166099771e-08, 6.779974845534173e-07, -4.182926011507132e-04, -1.531510647009293e-02, -2.027165671485752e-02, 3.229565204138781e+00, 4.137808778966947e+02, 8.616869153240495e+05, 5.716444411725189e+09, 6.078342376770812e+12, -6.584140197641791e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_vt84_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vt84", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.035627516781257e-09, 3.234408248555585e-09, 3.528892552856623e-09, 3.961465186859534e-09, 4.563853565701537e-09, 5.201924158083721e-09, 4.614901984456837e-09, -5.884245598189617e-09, -8.829636573995659e-08, -6.049421599299158e-07, 7.614850433572906e-06, 4.828122296426959e-04, 2.752297084275766e-02, 2.379369367007769e-01, 4.775072671565682e-03, -7.405760712668837e+00, 1.593301363993934e+01, 4.799795869186543e+01, 5.054981020975010e+02, 1.182461203174427e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_vt84_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_vt84", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.205734893664505e-05, -1.240133506281368e-05, -1.290308805712193e-05, -1.363611744423435e-05, -1.470390474437428e-05, -1.623507798817250e-05, -1.832636851902763e-05, -2.085500497452834e-05, -2.374807153059659e-05, -4.022141203675681e-05, -2.040793705040015e-04, 8.016468111757777e-05, -3.921173028150428e-02, -4.553587679209695e-01, -7.382672847921519e-01, -1.297335572602388e+00, -1.354350484507887e+00, 1.466559661936865e-01, 2.903115175672894e-04, 6.265152309523197e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
