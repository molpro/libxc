
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_6_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_6", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.784731817670705e+00, -4.690643618708431e+00, -4.558823965728406e+00, -4.376257679487217e+00, -4.127542235706518e+00, -3.796550632140802e+00, -3.370254520844175e+00, -2.844874343531245e+00, -2.231383255540083e+00, -1.562096353722877e+00, -9.593367410048876e-01, -6.328230769619795e-01, -5.704433805080558e-01, -4.873624701325570e-01, -3.437420427062557e-01, -1.955890999823755e-01, -8.571444649251390e-02, -2.741581517128474e-02, -5.685297510457207e-03, -6.294735452793861e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_6_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_6", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.988026565855573e+00, -5.856636446284589e+00, -5.672374220041735e+00, -5.416845084888295e+00, -5.068207468707617e+00, -4.603784807459904e+00, -4.007227359988950e+00, -3.285503941968403e+00, -2.503248545387465e+00, -1.778980910226828e+00, -1.151478200916744e+00, -7.893450565794276e-01, -7.890660811702641e-01, -6.122024342279287e-01, -3.979261650800810e-01, -2.328321658014501e-01, -1.065450465369551e-01, -3.439400642622385e-02, -7.124843969197811e-03, -7.876326853581682e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_6_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_6", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.957752729401966e-06, -8.614635109315138e-06, -9.651958506974649e-06, -1.135701952064005e-05, -1.432257876193823e-05, -1.990138577968434e-05, -3.155794194171396e-05, -5.920681276879535e-05, -1.318651560910980e-04, -3.109519073284570e-04, -7.359098990177122e-04, -3.974637465859726e-03, -1.924259225376132e-02, -4.705273612065840e-02, -1.423790241013124e-01, -4.192163956612973e-01, -1.493609797298954e+00, -1.314326906038220e+01, -3.309728064600793e+02, -2.913057423660670e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_6_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_6", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.543897204874227e-03, 8.707482412358854e-03, 8.946660924383284e-03, 9.298423351709823e-03, 9.819227781138142e-03, 1.059401334181058e-02, 1.173728150163258e-02, 1.330932454361219e-02, 1.467399938167791e-02, 1.227888682711992e-02, 4.673601351642117e-03, -4.257226996256535e-04, 3.196788615444446e-02, 5.203800639248765e-02, 5.628081702408074e-02, 3.435277244784739e-02, 1.101607328302645e-02, 3.201825456333625e-03, 7.307114748052997e-04, 8.841163399002170e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_6_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_6", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.566148086651225e-02, -1.644069674534226e-02, -1.762850915018893e-02, -1.948342188829201e-02, -2.247618260791545e-02, -2.750547687473460e-02, -3.628611204421669e-02, -5.131020639433551e-02, -6.953910289571630e-02, -7.288469024132856e-02, -1.313274405558589e-01, -4.943068986008880e-01, -9.450896314961831e-01, -1.441644024476938e+00, -1.979595924669977e+00, -3.187587557195902e+00, -3.127074390866531e+01, -3.621451367231145e+02, -8.633112459090595e+03, -7.077523819166975e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_6_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_6", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.710427082030750e-08, 6.549809347418026e-08, 7.970257974026729e-08, 1.054676232680987e-07, 1.569719604029745e-07, 2.745285590016531e-07, 5.921988780961812e-07, 1.603761278251107e-06, 4.351475807287224e-06, -1.131191476489618e-05, -3.688420903355448e-04, -4.375815170101126e-03, 2.999115356266733e-02, 1.491897073916722e-01, -7.499858713256168e-02, -2.765567753850554e+01, -5.498900212236072e+02, 4.606198905562824e+04, 2.320075115466348e+08, 1.563377915122148e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_6_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_6", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.967426900718723e-05, -2.149092916755239e-05, -2.440337506845938e-05, -2.929861914557737e-05, -3.809836977424546e-05, -5.546438262516970e-05, -9.410609798030801e-05, -1.896613282816957e-04, -3.771062377137522e-04, 1.042345884113949e-05, 9.714471292874701e-04, 1.080310048016665e-02, 8.947838346895019e-02, 4.948947157626736e-02, 4.927225775417696e-02, 1.150256919206941e+00, 2.480589015234558e+00, -1.264795073541481e+01, -5.135643593595358e+02, -4.745001348535792e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_6_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_6", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.900407398399635e-14, -7.483296604740500e-14, -1.052196238074048e-13, -1.713890888277304e-13, -3.439573807850729e-13, -9.255695190376676e-13, -3.732415453757173e-12, -2.567474163167331e-11, -3.312964760687018e-10, -7.730678407994001e-09, -3.721855624156349e-07, -3.347749457215037e-05, -1.094712439873925e-03, -1.502156739407303e-02, -6.255828273412444e-01, -9.230440944336146e+01, -1.004103423589465e+05, -1.246912017097835e+09, -4.514280829591854e+14, -2.299704866751607e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_6_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_6", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.865259557208622e-10, 2.258030574816038e-10, 2.971407934572210e-10, 4.406826432233309e-10, 7.753020727771436e-10, 1.738120143302117e-09, 5.466162818488546e-09, 2.700736483858979e-08, 2.243603676389434e-07, 2.641020226406695e-06, 3.518917097733547e-05, 1.163036528656820e-03, 1.407995453100328e-02, 1.081088812180375e-01, 2.216557011999779e+00, 6.340842143840219e+01, 3.128553728926191e+03, 9.170348109813816e+05, 2.856354048260449e+09, 1.989135867402807e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_6_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_6", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.322615202038415e-07, -3.788381613696522e-07, -4.574747630007359e-07, -5.999010937430863e-07, -8.852263082430377e-07, -1.545241186276432e-06, -3.412693052027328e-06, -1.029762216129178e-05, -4.334008562703235e-05, -1.903129456865539e-04, -4.763763429407366e-04, -2.183911762475340e-03, -6.104954566849709e-02, -2.464667937581559e-01, -1.663886778317877e+00, -9.537954702638828e+00, -4.036605156086652e+01, -3.727093593598645e+02, -1.041196240305818e+04, -9.955775062779936e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
