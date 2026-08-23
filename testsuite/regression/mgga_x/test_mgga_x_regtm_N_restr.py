
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_regtm_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtm", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.654175610768111e+00, -4.561508764692598e+00, -4.431727540055295e+00, -4.252091700429160e+00, -4.007622741640435e+00, -3.682917480226309e+00, -3.266413310774433e+00, -2.757947411946649e+00, -2.177946380054133e+00, -1.568633978049635e+00, -9.989623208605068e-01, -6.722237407773717e-01, -5.583834381356594e-01, -4.765376023469454e-01, -3.427608127476827e-01, -2.093439620421324e-01, -1.087768167968312e-01, -4.828817342721750e-02, -1.774529322771158e-02, -4.666581675938924e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_regtm_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.026479976280404e+00, -5.898343074337504e+00, -5.718602110615617e+00, -5.469232015894359e+00, -5.128671121947809e+00, -4.673942173238888e+00, -4.085958588844043e+00, -3.359454521555058e+00, -2.520491960684318e+00, -1.675753278703731e+00, -1.088476383744035e+00, -7.637621628991960e-01, -7.328820441289235e-01, -5.816874711642848e-01, -3.756743366263568e-01, -2.060170400678938e-01, -9.246262865107910e-02, -3.246642757920967e-02, -9.883722356458527e-03, -2.420244541369995e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtm_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.450034017520584e-06, -3.744565729196468e-06, -4.211322452068784e-06, -4.982739338474244e-06, -6.336576466981345e-06, -8.926097430081827e-06, -1.453831932820865e-05, -2.919630278364230e-05, -7.884825048982136e-05, -2.847682166190920e-04, -7.267953956229310e-04, -9.365844555277787e-04, -1.114428654490440e-02, -5.523344177578794e-02, -1.397299554577069e-01, -6.284066016622124e-01, -5.543482744278022e+00, -1.105873167457938e+02, -5.835950158752773e+03, -1.268539921080029e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtm_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.477031853636708e-03, 3.519382456361952e-03, 3.580168423462927e-03, 3.667449188328669e-03, 3.793328098994913e-03, 3.978673826321838e-03, 4.273830986580410e-03, 4.853077891442355e-03, 6.182178559414596e-03, 7.643705011785472e-03, 9.244001901841122e-04, -1.052969327373566e-02, 7.315085588382481e-03, 5.550831718864768e-02, 4.154165099937961e-02, 3.019722593081139e-02, 2.250817907663633e-02, 1.496023583986324e-02, 7.362225230469160e-03, 2.256545382385064e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtm_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.315176789906491e-02, -1.373195060396739e-02, -1.460535322248867e-02, -1.594341292100997e-02, -1.803875039505740e-02, -2.139692941735853e-02, -2.684328665832934e-02, -3.538973022422281e-02, -4.785477452800399e-02, -8.248823800701888e-02, -1.920667545718581e-01, -5.079226953723023e-01, -7.365495227663572e-01, -1.487223237998015e+00, -1.921188544569740e+00, -6.390562582273201e+00, -7.785723461917226e+01, -1.456076210412929e+03, -5.932809804856576e+04, -1.063274331934181e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtm_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.160082404427836e-08, 1.247590349282329e-08, 1.361754045206834e-08, 1.471683999772300e-08, 1.372420377250515e-08, -1.194061915896342e-09, -1.059137008878828e-07, -8.803550449081684e-07, -7.068258842500131e-06, -3.917639997271727e-05, 3.093972680288724e-04, -6.535467311678043e-03, 1.241421058895445e-03, 6.499132113972943e-03, -1.128500238251354e+00, 9.912803138303708e+00, 9.337673050708747e+03, 7.678038876941282e+06, 4.197107045185677e+10, 5.981749639643706e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtm_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.083358227659811e-05, 2.368362480901977e-05, 2.845091153152045e-05, 3.696159557149624e-05, 5.361938008237858e-05, 9.064861881651526e-05, 1.877097180259079e-04, 4.875156103487360e-04, 1.376078630517787e-03, 2.227967661718656e-03, -4.713628487484342e-03, 1.553360069143348e-02, 5.538528708652874e-02, 3.284421232804338e-01, 7.754419623560451e-01, -9.279631862439803e-01, -7.035041999948211e+01, -1.994462750936235e+03, -1.022532308920970e+05, -2.027584741647891e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtm_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.056386048786311e-13, 5.218626541754454e-13, 7.497267515855887e-13, 1.261923885375950e-12, 2.663910595627527e-12, 7.751518428727509e-12, 3.514521719307382e-11, 2.805498668963755e-10, 3.875735492307047e-09, 6.021377179844272e-08, -5.947479555866264e-06, 5.357541848236765e-05, -1.577961931253831e-02, 8.661061578878367e-03, 3.794670750613792e+00, -8.819134713042095e+01, -1.614482192671390e+06, -4.512001239794012e+10, -3.031243146572789e+16, -3.370998631518054e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtm_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.789653221057544e-10, -6.966726253859123e-10, -9.096199856550427e-10, -1.336082482580616e-09, -2.325047369036034e-09, -5.153377768133343e-09, -1.594899576641774e-08, -7.395810574650983e-08, -4.448722696072456e-07, -1.205739786116254e-06, 7.943644260015781e-05, 6.868652798739191e-04, 3.081312855786338e-02, 1.840990087796248e-01, -7.317549518923565e-02, 5.359637260428352e+01, 1.696079835844091e+04, 1.475808646029787e+07, 9.287522921513766e+10, 1.472593415489061e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtm_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.505735811876883e-07, 7.409220926062042e-07, 8.941475166496948e-07, 1.173616562738364e-06, 1.739263318642107e-06, 3.063317775939483e-06, 6.798471243261962e-06, 1.918801582385683e-05, 5.188956079389617e-05, 8.801538867865148e-06, -7.954633647314232e-04, -1.605287384668774e-03, -5.745013999210130e-02, -5.322202243177147e-01, -5.611898574595621e-01, -6.787820536597806e+00, -1.445108535314358e+02, -4.106422138596336e+03, -2.379002399968857e+05, -5.269159678295702e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
