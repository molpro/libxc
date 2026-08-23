
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_msrpbel_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msrpbel", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.541611980311298e+00, -4.452708507045257e+00, -4.328195508500356e+00, -4.155846786880486e+00, -3.921286375670200e+00, -3.609733716961556e+00, -3.210143415305353e+00, -2.722744456476926e+00, -2.168824181471771e+00, -1.577512941357404e+00, -1.002726292818314e+00, -6.216991133162856e-01, -5.589150779659573e-01, -4.753938721246667e-01, -3.403220492941802e-01, -2.178947865947151e-01, -1.261166026750124e-01, -4.238120638192029e-02, -8.774367452886237e-03, -9.701687044429635e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_msrpbel_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msrpbel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.859495012045413e+00, -5.737417380252111e+00, -5.566217164047027e+00, -5.328762460028542e+00, -5.004547475456061e+00, -4.571581960007822e+00, -4.010865951816091e+00, -3.313227060747034e+00, -2.477468246691185e+00, -1.454224035504243e+00, -9.696013538548732e-01, -8.138552732617915e-01, -7.504699741841993e-01, -5.960417134318996e-01, -3.493175855185856e-01, -1.799962771156680e-01, -1.266243894702938e-01, -5.650827376435156e-02, -1.169915660384832e-02, -1.293558272590618e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msrpbel_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msrpbel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.120550447746715e-06, -2.301297911385096e-06, -2.588596801457741e-06, -3.065897927916454e-06, -3.911503326584084e-06, -5.558199723925135e-06, -9.258127042440178e-06, -1.974455325384640e-05, -6.578513492150307e-05, -4.936151528227421e-04, -1.427511274335793e-03, -5.527647003881029e-03, -1.224416072308038e-02, -4.962823219008677e-02, -2.101339556076022e-01, -6.676749466854794e-01, -3.271068192931545e+00, -3.184689528590323e-06, -2.839475444401649e-188, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msrpbel_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msrpbel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.013042684218751e-05, 4.447063421242375e-05, 5.158660576099936e-05, 6.395395092771240e-05, 8.734853518702708e-05, 1.374154278266211e-04, 2.656788047004846e-04, 6.922423655546919e-04, 2.741547594031295e-03, 1.512303594278212e-02, 5.300289108346956e-03, 4.687866220213966e-03, 1.521626998120231e-02, 5.597132832017859e-02, 7.356592040699814e-02, 9.662307892462162e-03, 5.181443782891450e-03, 1.527073771381245e-12, 7.045802417391970e-200, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msrpbel_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msrpbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.160709939927161e-02, -1.208081095057945e-02, -1.279037123602768e-02, -1.386964985894749e-02, -1.554214569558332e-02, -1.817842658222942e-02, -2.230200953587210e-02, -2.782854893599725e-02, -2.817706017699675e-02, -1.678751652048952e-01, -4.646977815457652e-01, -8.094448725224097e-01, -1.226337391651115e+00, -1.594751189097115e+00, -5.099297083928470e+00, -3.191359679783727e+01, 1.163958945235093e+02, -5.852398318369490e+02, -1.365370822982718e+04, -1.116831697629218e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msrpbel_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msrpbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.144435492528740e-09, -6.854996587851706e-09, -1.010882416368812e-08, -1.703393904123128e-08, -3.424031550671687e-08, -8.713861290956785e-08, -3.051403917724333e-07, -1.647284702230994e-06, -1.549267423100174e-05, -6.054306858163112e-05, 4.703229831668808e-04, 5.946187817967642e-03, -5.731332362727428e-02, 2.781162481394668e-01, 4.191275763558957e+00, 5.054685360127872e+02, -5.300864563042363e+03, -5.272202856110947e+00, -1.181009834509870e-178, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msrpbel_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msrpbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.880964817490692e-05, 3.245097410697919e-05, 3.849569258475095e-05, 4.917884176998269e-05, 6.983567732341254e-05, 1.152661050254737e-04, 2.353155318916470e-04, 6.459352051866149e-04, 2.603556562783166e-03, 6.182293456840785e-03, 2.733193480584152e-03, 2.590204739269627e-02, 3.075358300332617e-01, -4.910725761116224e-02, -6.742919666524062e-01, -4.616053755537885e+01, -6.257078185604504e+01, 6.072870260626992e-07, 2.735870854337525e-190, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msrpbel_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msrpbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.924888473241922e-13, 7.563017402366859e-13, 1.073973564096530e-12, 1.776834960013308e-12, 3.658327346734636e-12, 1.029392399287686e-11, 4.519575989501385e-11, 3.730591305034238e-10, 7.431607183207495e-09, 2.057288824663979e-07, -1.595526765276351e-06, -3.219274389969282e-05, -1.664534736684607e-02, 1.730903772293943e-02, -5.027962351428498e+00, -9.574127573059537e+03, -9.417367885300788e+05, 1.215838219328739e+04, 3.219113496957871e-173, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msrpbel_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msrpbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.368961495677993e-10, -1.004830784752914e-09, -1.306721924998130e-09, -1.905337164620686e-09, -3.272572610067614e-09, -7.101966189287991e-09, -2.150262932039378e-08, -1.044082687557403e-07, -9.773002439538511e-07, -8.878301373788157e-06, 4.129180754746420e-05, 5.536664741381561e-04, 5.648118195304921e-02, -8.710898276504236e-03, 3.305018536966045e+00, 9.274694513339794e+02, 1.821654021134848e+04, 7.427074924913993e-03, -6.466980009342398e-185, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_msrpbel_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_msrpbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.198789290315898e-06, 1.353846467570298e-06, 1.612313272012396e-06, 2.071905389991472e-06, 2.968679978306790e-06, 4.968574920875459e-06, 1.037324486922672e-05, 2.962459663898879e-05, 1.302480652197585e-04, 3.934538464722965e-04, -6.078811899965801e-04, -3.077510219455533e-03, -1.879364241808496e-01, -8.647889936724256e-03, -1.985036458204134e+00, -8.689388910088394e+01, -1.602521008337524e+02, -3.417006548182606e-06, -3.475010244071305e-191, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
