
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_8_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_8", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.938820655535392e+00, -4.841710477151027e+00, -4.705547824710668e+00, -4.516719938843748e+00, -4.258897030296479e+00, -3.914374631018650e+00, -3.467037359564753e+00, -2.906276289718965e+00, -2.230092732220311e+00, -1.476823117811094e+00, -8.491895462101015e-01, -5.725253280668896e-01, -5.729501206695483e-01, -4.901840421747847e-01, -3.294674972596027e-01, -1.725144431241242e-01, -7.247895991693336e-02, -2.299421485764667e-02, -4.768545058184298e-03, -5.283410257352169e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_8_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_8", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.157502667421768e+00, -6.024005834879612e+00, -5.837017058305788e+00, -5.578206608441215e+00, -5.226207280757537e+00, -4.759825109621509e+00, -4.166299226686589e+00, -3.458072111803765e+00, -2.686340609806378e+00, -1.866598951564728e+00, -1.103892095252784e+00, -7.995822624309530e-01, -8.383688389728594e-01, -6.530297318301289e-01, -4.242125901560388e-01, -2.160265234780053e-01, -8.865829372826670e-02, -2.794966069917239e-02, -5.770605371210258e-03, -6.375337605423711e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_8_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_8", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.827364723768873e-06, -9.558655207019593e-06, -1.071385285583644e-05, -1.261348121241077e-05, -1.591918348367989e-05, -2.214087762454180e-05, -3.513843361024801e-05, -6.586939117355870e-05, -1.454924685196101e-04, -3.342689695021504e-04, -7.511323855930351e-04, -3.822693086933043e-03, -2.037443824758514e-02, -5.086116593473877e-02, -1.521604023485878e-01, -4.522297629814203e-01, -1.770971439860291e+00, -1.669304366878302e+01, -4.270290568630556e+02, -3.773238870629485e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_8_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_8", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.644019282644271e-03, 9.894235491103588e-03, 1.026631941910042e-02, 1.082732965871078e-02, 1.168904769232839e-02, 1.304282924510595e-02, 1.520768594420570e-02, 1.855387206765235e-02, 2.217046572240468e-02, 1.906777415419732e-02, 7.974316746855942e-03, 7.305358031028783e-03, 5.148508000671612e-02, 7.969314012020420e-02, 9.084082517235813e-02, 4.808828000903138e-02, 1.398515852439405e-02, 4.096762764727075e-03, 9.430798271607308e-04, 1.145186853691151e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_8_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_8", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.595292330131795e-02, -1.672051649045999e-02, -1.788468207837993e-02, -1.968824983451634e-02, -2.256104000998953e-02, -2.728715981329627e-02, -3.525850939059955e-02, -4.842837646581402e-02, -6.949264414702516e-02, -1.338596199903969e-01, -2.953851673510602e-01, -7.818742091983424e-01, -8.911801644208759e-01, -1.345098095617054e+00, -2.808730624462016e+00, -7.321284896035527e+00, -3.203214322133700e+01, -3.204653620285366e+02, -7.557578174568725e+03, -6.206136275888876e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_8_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_8", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.490999899203197e-08, 7.452192125203001e-08, 9.080816577863700e-08, 1.204025172076501e-07, 1.797132888391066e-07, 3.155668794138769e-07, 6.843449651338175e-07, 1.864848717808058e-06, 5.157141517541767e-06, -8.187320251007484e-06, -3.281806703132736e-04, -4.798238229343249e-03, 2.813957820885826e-02, 1.562549439169268e-01, -2.036862175076653e-02, -2.140222772269292e+01, -1.241642323978982e+02, 1.708381429159094e+05, 5.952991224185218e+08, 3.956748865078953e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_8_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_8", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.801708964279266e-05, -4.204913061918436e-05, -4.858707478510618e-05, -5.973939367514469e-05, -8.014028102472259e-05, -1.210421879398369e-04, -2.118621159389257e-04, -4.191651418765731e-04, -6.349846662532202e-04, 1.274027214039207e-03, 5.959498971219423e-03, 3.583455868218251e-02, 5.407583738575341e-02, -5.529466618163884e-02, 4.466049743100240e-01, 3.502830955979248e+00, 2.906438402961043e+00, -3.907511283682511e+01, -1.310900785553942e+03, -1.200837057799227e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_8_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_8", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.336208104798336e-14, -1.186056509045295e-13, -1.671823561611044e-13, -2.733494326956193e-13, -5.518078808232926e-13, -1.498900122066118e-12, -6.139816216409711e-12, -4.340653279046566e-11, -5.886411016386247e-10, -1.487342369697288e-08, -7.219748281848208e-07, -5.949098006472789e-05, -1.749892548163537e-03, -2.500379913653362e-02, -1.155619534316544e+00, -1.876942195856845e+02, -1.858673239162726e+05, -2.204892114330193e+09, -7.963786913708796e+14, -4.067870475311840e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_8_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_8", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.321900092668132e-10, 2.814980324180339e-10, 3.712172631685630e-10, 5.522109048814797e-10, 9.756525394237434e-10, 2.199841715069062e-09, 6.965374840070537e-09, 3.456546758036852e-08, 2.837024684265913e-07, 3.162103926313313e-06, 3.843673674626927e-05, 1.199582663677334e-03, 1.698139237375464e-02, 1.335786269830161e-01, 2.652463536897833e+00, 7.387887089380276e+01, 4.062326570941828e+03, 1.307128318569568e+06, 4.156218378091352e+09, 2.907026660600291e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_8_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_8", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.839513741511815e-08, -5.277388010327005e-08, -7.974323945713841e-08, -1.358248252095652e-07, -2.698967614786428e-07, -6.561512025250528e-07, -2.075986262541579e-06, -9.069053191762739e-06, -5.259544980594543e-05, -2.673621110017706e-04, -6.930513579253502e-04, -4.766832767871304e-03, -5.636194643904503e-02, -2.505168778143702e-01, -2.304144423910222e+00, -1.274645815752382e+01, -5.208817333031113e+01, -5.086863123690064e+02, -1.447353961682694e+04, -1.389872331631224e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
