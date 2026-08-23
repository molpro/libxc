
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_gam_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_gam", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.639098677212971e+00, -4.538475278032824e+00, -4.397749134958834e+00, -4.203406004034494e+00, -3.939937557731505e+00, -3.592427152100930e+00, -3.152762356728227e+00, -2.631908932728184e+00, -2.078426106689591e+00, -1.575971393813098e+00, -1.100175560725309e+00, -7.125660917645773e-01, -6.163655598671994e-01, -5.037099502221408e-01, -3.490210498084420e-01, -2.010933055045971e-01, -1.791037137062283e-01, -1.051765579365961e-01, -2.436645631455361e-02, -2.727307704839838e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_gam_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_gam", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.704800369504814e+00, -6.564485199922997e+00, -6.367022447284402e+00, -6.091681538506905e+00, -5.712615289254150e+00, -5.199741992964007e+00, -4.521847651564472e+00, -3.654855267465263e+00, -2.612154156268502e+00, -1.558395801551953e+00, -9.304346985421430e-01, -9.167793586911407e-01, -8.086215729015693e-01, -6.430019117101858e-01, -4.470238381525330e-01, -1.576538661647645e-01, 1.304714046334602e-02, -1.141785820168381e-01, -3.214277923505048e-02, -3.635050530014717e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_gam_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_gam", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.688724938571513e-06, 6.005543027648434e-06, 6.479335632872422e-06, 7.194457169398568e-06, 8.275650896907322e-06, 9.857356486699210e-06, 1.175257939393046e-05, 1.116169478616921e-05, -1.251608190198177e-05, -1.968398073392615e-04, -1.389143487654993e-03, -2.480408874006962e-03, -4.536266157670193e-03, -1.007571031186915e-02, -2.181589791469411e-02, -6.455835912606999e-01, -1.715687115544468e+01, -5.686489271950072e+01, -7.540427637811818e+01, -8.382873829063853e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_gam_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_gam", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.259197603978399e-02, -1.328617850337396e-02, -1.437094130123392e-02, -1.613128200928350e-02, -1.915047674706813e-02, -2.476074000019307e-02, -3.641387249394213e-02, -6.415753300569024e-02, -1.375511870643504e-01, -3.225252753404640e-01, -8.229396975229885e-01, -5.992380632782531e-01, -7.118682942485822e-01, -1.059889297321120e+00, -2.812187710781783e+00, -5.693195511654663e+01, 3.054161001103407e+02, 1.692289040862579e+03, -3.326309446558869e+04, -3.130176078525069e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_gam_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_gam", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.450240080856722e-09, -3.060664537107019e-09, -9.883623460936236e-11, 6.907429685319254e-09, 2.580483274501294e-08, 8.613810317509778e-08, 3.256463864083864e-07, 1.574265009323239e-06, 1.038884029208032e-05, 9.407895893543349e-05, 1.731316077511029e-03, 8.173279231357791e-03, 1.703683181411558e-02, 3.477586383790464e-02, 9.042621100407636e-01, 2.852210578669137e+02, -2.064927935408968e+04, -6.404431974673241e+06, -1.051178041611918e+09, -8.684408706887097e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_gam_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_gam", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.372301790598561e-13, -4.227354404888908e-13, -5.842696373097113e-13, -9.277337517989567e-13, -1.791854612796141e-12, -4.548362169613138e-12, -1.676286031415278e-11, -1.003988447257974e-10, -1.053320228093357e-09, -1.737310689446422e-08, -1.485577200080026e-06, -1.624177038014141e-04, 3.089770042995413e-04, 6.388572082729040e-03, -8.699532123304388e-01, -1.200601914557562e+03, 2.976254662468692e+06, 1.975076902074789e+10, 3.821020464959217e+14, 2.448347663103433e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
