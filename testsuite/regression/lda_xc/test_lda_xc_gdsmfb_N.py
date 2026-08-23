
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_gdsmfb_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_gdsmfb", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.271748529424009e+00, -4.187140313603949e+00, -4.068550684333815e+00, -3.904206529611860e+00, -3.680128268192669e+00, -3.381622563466322e+00, -2.996907058492485e+00, -2.523839003535249e+00, -1.980096117756401e+00, -1.416975618113631e+00, -9.457664508835588e-01, -7.286586946547088e-01, -6.443670415030696e-01, -5.232916822537624e-01, -3.668968382436388e-01, -2.165219459184757e-01, -1.029220576549375e-01, -3.627437549037957e-02, -8.319593459676736e-03, -1.005705334127408e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_gdsmfb_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_gdsmfb", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.667874316687261e+00, -5.667831735809663e+00, -5.555227060550751e+00, -5.555138089335553e+00, -5.397358258218111e+00, -5.397171532774650e+00, -5.178626318500099e+00, -5.178231878203358e+00, -4.880494334382101e+00, -4.879653029652761e+00, -4.483571720116997e+00, -4.481751051671805e+00, -3.972571735588916e+00, -3.968543498873226e+00, -3.345612252084230e+00, -3.336391595036966e+00, -2.628719212620105e+00, -2.606501280264056e+00, -1.896462704439845e+00, -1.839219336414736e+00, -1.302070933207982e+00, -1.153581817609124e+00, -1.018844130283532e+00, -7.604366854795762e-01, -8.984253396499525e-01, -6.619124141396093e-01, -7.267904893843339e-01, -5.493855914341859e-01, -5.054132615290077e-01, -3.866084968349564e-01, -2.941419277656785e-01, -2.294534311256370e-01, -1.372998468032104e-01, -1.134997659305712e-01, -4.776553824381864e-02, -4.344009255690117e-02, -1.095179779307077e-02, -1.052044892574829e-02, -1.332245880422393e-03, -1.245675821624319e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_gdsmfb_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_gdsmfb", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.014821857551238e-02, -6.145036587445630e-04, -2.014853033109581e-02, -2.098125092786902e-02, -6.478754732137486e-04, -2.098194328857362e-02, -2.223843283389761e-02, -6.990485352197096e-04, -2.224001893985830e-02, -2.417576147442262e-02, -7.797453660580156e-04, -2.417956103117040e-02, -2.725174738770881e-02, -9.122218415771113e-04, -2.726145375367408e-02, -3.234842493155730e-02, -1.142643920914080e-03, -3.237562519057745e-02, -4.132076930334738e-02, -1.578130495574856e-03, -4.140785165104336e-02, -5.851831282277191e-02, -2.505196105375737e-03, -5.885586801190108e-02, -9.548091720985596e-02, -4.840006977324590e-03, -9.719702523237132e-02, -1.856248255422060e-01, -1.215859135614100e-02, -1.981068302136104e-01, -3.999314097131964e-01, -3.873902960848408e-02, -5.198669724292566e-01, -6.609897837718316e-01, -9.398234581919873e-02, -1.271662442509966e+00, -8.570969795846388e-01, -1.361902539974104e-01, -1.711251459463581e+00, -1.330282404580716e+00, -2.430523229795312e-01, -2.524766019810891e+00, -2.839849177183742e+00, -6.808912536599494e-01, -5.341689695979437e+00, -8.913163239840131e+00, -3.158071206977224e+00, -1.649624770852444e+01, -4.593338193894856e+01, -2.534958190289327e+01, -7.564862446027050e+01, -4.667022289444934e+02, -3.706354737737838e+02, -5.969066997645708e+02, -1.206555221519621e+04, -1.145636992567445e+04, -1.388708708515431e+04, -1.116258772442397e+06, -1.061226968636980e+06, -1.412373329201849e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
