
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_mn12_sx_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn12_sx", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.442731024163173e+00, -3.503342466313236e+00, -3.569346970383152e+00, -3.623004471564959e+00, -3.622942789302481e+00, -3.489745160692137e+00, -3.109018226840793e+00, -2.422211843010520e+00, -1.647819340580166e+00, -1.049723917410910e+00, -4.203363131795411e-01, -2.869343027217790e-01, -4.300193782619777e-01, -3.577482699808161e-01, -2.916632081683695e-01, -1.647262102880250e-01, 3.585935126470018e-02, 1.978630296018721e-02, 4.578450383051453e-03, 5.335528938828451e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_mn12_sx_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn12_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.086006733528141e+00, 3.494041511693257e+00, 2.676338953052323e+00, 1.576275317798313e+00, 1.685325757064987e-01, -1.454115192780663e+00, -2.898327378535250e+00, -3.326394228421765e+00, -2.336540078653234e+00, -1.735238616195238e+00, -1.248175343205462e+00, -1.025412915080540e+00, -6.613432566285445e-01, -4.755879452813839e-01, -1.826787246391303e-01, -3.695241597149163e-01, -7.923246770873528e-04, 3.389902271727337e-02, 6.119193840829104e-03, 7.102673014525067e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn12_sx_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn12_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.404557954826065e-05, -8.759890177516849e-05, -9.276331165622773e-05, -1.002348274487094e-04, -1.108389523674419e-04, -1.249785376689422e-04, -1.401661369398835e-04, -1.427432694562165e-04, -9.697971631081236e-05, -6.398487457944022e-05, -1.368142399509204e-03, -1.629321391264969e-02, -6.809691359022678e-03, -1.166936210416265e-02, -2.212051961646414e-01, -7.046177539670961e-01, -4.054168173753441e+00, -3.300958203516825e+01, -4.690957132578271e+01, -5.209575494859952e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn12_sx_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn12_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.864505755593344e-02, -1.056515626635752e-02, 7.325179407784598e-04, 1.612153931221462e-02, 3.592125170802713e-02, 5.808718823792261e-02, 7.391789069668904e-02, 6.400124631369949e-02, 2.186539851328204e-02, 1.291226334628120e-02, 3.964422029174719e-02, 7.316372481238137e-02, 4.849108080521741e-02, 1.968137223274002e-02, 3.149589371536263e-02, 2.015095073530107e-01, 7.924781853339420e-02, 4.583053926482978e-03, 5.373162309893190e-05, 8.445060537305590e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn12_sx_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.291243370910742e-01, 1.357899963456142e-01, 1.451656963175018e-01, 1.578298012836130e-01, 1.730593791845601e-01, 1.846030955220388e-01, 1.685681482833616e-01, 7.323950667941324e-02, -3.022049543989957e-02, 2.665628277107119e-01, -1.640018227111608e-01, -4.092981684156842e-01, -8.688704961807979e-01, -3.099979160885487e+00, -3.403641461669230e-01, 5.534226798375815e+01, -4.055890491692344e+02, 1.319474542813335e+03, 8.365489098068947e+03, 6.095349402123502e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn12_sx_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.548102020802405e-07, -2.001418984867063e-07, -2.806535168265196e-07, -4.353321154435333e-07, -7.642179650612849e-07, -1.556505813124687e-06, -3.750299930258454e-06, -1.054782345278141e-05, -3.010606346234871e-05, -6.492427599321902e-05, -1.408695942447552e-03, 8.757093184428964e-02, 2.444721612441020e-02, 4.529636554880926e-01, 3.629659266007306e+00, -4.052310814032298e+02, 9.583757323926737e+03, -3.470702108890194e+06, -6.524671994740765e+08, -5.397074211483355e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn12_sx_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.510890568191087e-03, -2.616702586288460e-03, -2.756252937579643e-03, -2.920220244010343e-03, -3.044969442641955e-03, -2.882982632392727e-03, -1.659831908432113e-03, 2.116956443662162e-03, 5.635944974232592e-03, -6.118962253757196e-03, 1.194327772975381e-02, -1.215029111069533e-01, 1.399100955899584e-01, 5.421576176071633e-01, -3.007029958567150e+00, 7.519273048934751e+00, 2.049337676508528e+02, 4.250144086374112e+02, 5.632488523596536e+02, 6.560453394679555e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn12_sx_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.428092160678683e-12, 1.760266460716292e-12, 2.372467420387499e-12, 3.626252275954544e-12, 6.602639623614166e-12, 1.525858248697735e-11, 4.822781360811678e-11, 2.252308319771828e-10, 1.826572755659057e-09, 6.290499218484623e-08, 1.252810930910826e-05, 1.132391800210817e-03, -4.455501502005165e-03, 1.737111029417051e-02, 7.494743362048455e+00, 2.506299964491452e+03, -2.580449777410340e+05, 1.094604012243588e+10, 2.372702584473383e+14, 1.521501151634256e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn12_sx_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.488992968733903e-08, 1.703759217479167e-08, 2.062456440186917e-08, 2.698885799615627e-08, 3.923307438957939e-08, 6.533391756085707e-08, 1.276701313505224e-07, 2.871279542263423e-07, 5.739014936100809e-07, -1.817972004909667e-06, -6.525830350013777e-05, -5.262017751003956e-03, -3.138611227495860e-03, -2.781132798755868e-01, -3.902780513329258e+00, 2.527419865403418e+01, -3.359271938083041e+02, -2.402402361988845e+04, -1.970039806814105e+05, -2.227276969349778e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mn12_sx_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mn12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.814651175984523e-05, 2.798114307503506e-05, 2.715991198036355e-05, 2.450482604823975e-05, 1.678705451648105e-05, -4.910717861983060e-06, -6.336416667238059e-05, -1.924187571878445e-04, -2.686857605314601e-04, 2.638426903752826e-04, 1.924311822729162e-04, 1.337056690095853e-02, -6.501564275839168e-02, 2.288150217046247e-01, 4.307831347722499e+00, -1.356369806631414e+01, -1.791841783231453e+02, -4.065496004936702e+02, -6.023688315906702e+02, -7.486082083468472e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
