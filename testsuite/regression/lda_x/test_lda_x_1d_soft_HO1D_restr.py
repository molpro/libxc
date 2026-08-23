
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_1d_soft_HO1D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_1d_soft", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.115840582218724e-01, -4.115836347419699e-01, -4.115825204800113e-01, -4.115795923611814e-01, -4.115719133819871e-01, -4.115518405547419e-01, -4.114996368432880e-01, -4.113649278268725e-01, -4.110213258088418e-01, -4.101589861251630e-01, -4.080385629265758e-01, -4.029348439866485e-01, -3.908315223836121e-01, -3.622326623840082e-01, -2.965397545646946e-01, -1.737149103242095e-01, -4.793777798872813e-02, -3.373217419758148e-03, -2.465681197955729e-05, -4.500675956497448e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_1d_soft_HO1D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_1d_soft", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.946598706930223e-01, -4.946597635567246e-01, -4.946594816533618e-01, -4.946587408113009e-01, -4.946567976746450e-01, -4.946517163963445e-01, -4.946384883963961e-01, -4.946042671759298e-01, -4.945164108012358e-01, -4.942923171547570e-01, -4.937193465623363e-01, -4.922118860447982e-01, -4.879120581551851e-01, -4.738233749767292e-01, -4.232244999313252e-01, -2.787053434113458e-01, -8.466144639890916e-02, -6.295623595603431e-03, -4.740956050849785e-05, -8.797630648093454e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_1d_soft_HO1D_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_1d_soft", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.862611201047620e-02, -1.862649338892650e-02, -1.862749689549853e-02, -1.863013411802417e-02, -1.863705127431423e-02, -1.865513989003259e-02, -1.870223194594176e-02, -1.882407578734507e-02, -1.913698708499045e-02, -1.993577369270338e-02, -2.198226923120777e-02, -2.739314525934411e-02, -4.301275319003045e-02, -9.571985231155963e-02, -2.999074165130082e-01, -1.018785336317032e+00, -2.771729291380753e+00, -5.982525564641253e+00, -1.144957474678359e+01, -2.059232285415228e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
