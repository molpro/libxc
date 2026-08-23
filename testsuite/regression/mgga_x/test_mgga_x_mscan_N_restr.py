
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_mscan_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mscan", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.884492334344283e+00, -4.785600081052349e+00, -4.646985942257243e+00, -4.454880940794714e+00, -4.192920074093144e+00, -3.843850923747865e+00, -3.393650261514499e+00, -2.838945178994192e+00, -2.196844612810779e+00, -1.503380325680488e+00, -8.321635424694777e-01, -5.609137381852186e-01, -5.658145714724087e-01, -4.919055588590481e-01, -3.320794458357120e-01, -1.728689643926167e-01, -6.616194304987946e-02, -1.688972620610642e-02, -2.219081382197897e-03, -1.014935476946993e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_mscan_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.406802402208660e+00, -6.273584117023139e+00, -6.086806482872220e+00, -5.827847486386681e+00, -5.474502453245663e+00, -5.003193200373395e+00, -4.394304665988838e+00, -3.641532975275042e+00, -2.761475299211686e+00, -1.752631437161086e+00, -1.120311584179082e+00, -7.923305490635875e-01, -8.847277002550710e-01, -6.627861261580706e-01, -4.033959651369971e-01, -1.984854507597238e-01, -6.228093395510619e-02, -2.547220685499015e-02, -3.954824881134099e-03, -1.955051426126316e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mscan_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.252374890369113e-06, -3.517650365284745e-06, -3.936716033747125e-06, -4.626373106802713e-06, -5.830019709826477e-06, -8.116077454449101e-06, -1.302504340071924e-05, -2.569505091102392e-05, -7.022490033529060e-05, -3.997396462634336e-04, -9.225222672849150e-04, -4.986550092004178e-03, -2.872340927119024e-02, -4.813631306256097e-02, -2.049644406931014e-01, -7.369804859876236e-01, -7.061513623384917e+00, -2.439943417077860e+00, 2.510366737621492e+02, 1.268831657127545e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mscan_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.814926919524462e-03, 4.903130593460069e-03, 5.032226254383052e-03, 5.222588924530451e-03, 5.506354243362429e-03, 5.936349800359901e-03, 6.606426849730049e-03, 7.717404367597330e-03, 9.956842749910834e-03, 1.941658552916603e-02, 1.122716910208464e-02, 9.285989400743176e-03, 8.268656431067233e-02, 7.976725097976747e-02, 1.105347864186745e-01, 7.208654946831002e-02, 6.030032624830428e-02, 3.518401053869215e-03, 7.116770514100119e-05, 1.744518436252082e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mscan_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.326026861221018e-02, -1.383740687525053e-02, -1.471024455120270e-02, -1.605899107470862e-02, -1.820739444709168e-02, -2.177729408458607e-02, -2.805772674457274e-02, -3.992961889412974e-02, -6.409526929600831e-02, -1.275075879609412e-01, -3.440645208375678e-01, -1.144061961154663e+00, -1.918006683812577e+00, -1.580243452634669e+00, -3.989805201156393e+00, -2.628605144285414e+02, -8.174955149716155e+02, -2.405917266499337e+03, -1.810726881450288e+04, -4.855734945830124e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mscan_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.211277989682857e-08, 1.345657240724401e-08, 1.558836289241322e-08, 1.906518808800292e-08, 2.480432940729085e-08, 3.338943135086532e-08, 3.444964076399081e-08, -1.302716456080404e-07, -3.237147516805571e-06, -1.087688157192355e-04, -1.827872324927453e-04, -3.712199198388849e-03, -9.196831884396202e-02, 2.590065466099266e-01, -1.034471650985142e+00, 4.969408475496088e+03, 1.582531294952939e+05, 1.295728371686887e+07, 7.432859898112180e+09, 7.717374180858631e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mscan_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.038507618981036e-06, 6.010671492725341e-06, 7.666045076753783e-06, 1.068741998008969e-05, 1.675862032118359e-05, 3.068225119468758e-05, 6.894531327520967e-05, 2.038925703601045e-04, 8.918174390183885e-04, 7.821555206727466e-03, 5.666631845662101e-03, 6.654924937646282e-02, 5.767983941992971e-01, -8.840401690230155e-02, 1.911459572263704e+00, -4.578474580985142e+02, -1.185549004938992e+03, -3.145823621174379e+03, -1.327488609963316e+04, -4.951037952599364e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mscan_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.719125666334929e-13, 3.453725549287446e-13, 4.868696625566896e-13, 7.968124482126337e-13, 1.614098332200663e-12, 4.431406542470079e-12, 1.874727063600065e-11, 1.469494915794747e-10, 2.856374875453651e-09, 2.622263653061598e-07, -1.133823099721580e-05, 4.302566801442696e-04, -2.572071906942482e-02, 2.488333902865400e-01, 1.987803502115427e+01, -9.747434261853967e+04, -3.269798766487823e+07, -8.347336935065010e+10, -5.241630291197586e+15, -3.150766840594162e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mscan_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.231737196904258e-10, -3.870412686094819e-10, -5.014345438770629e-10, -7.270255248584399e-10, -1.238032081983855e-09, -2.651395711549736e-09, -7.868247392691766e-09, -3.723188747195090e-08, -3.536824650594559e-07, -1.184793950149765e-05, 1.636454590510888e-04, 7.915372713152059e-04, 1.012930872475076e-01, -3.672156731066991e-01, -9.916717716264598e+00, 9.089478056553142e+03, 2.571928409297649e+05, 2.108879805646782e+07, 1.023583613911417e+10, 2.877421024407802e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mscan_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.934391681164751e-07, 4.437390280207992e-07, 5.274295792536690e-07, 6.758467251298226e-07, 9.643436205169604e-07, 1.604401726806428e-06, 3.324266979213224e-06, 9.458330292012084e-06, 4.386269929204793e-05, 5.374132763546619e-04, -2.182949516883315e-03, -7.092550309555259e-03, -3.649918155128370e-01, 5.566091660598235e-01, 5.002826505435279e+00, -8.474177004902077e+02, -2.026302367004389e+03, -5.448757548005423e+03, -2.346055584351959e+04, -8.904836758945136e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
