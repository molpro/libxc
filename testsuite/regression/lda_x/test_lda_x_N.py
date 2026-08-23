
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.162997500470421e+00, -4.078904939626474e+00, -3.961052837441001e+00, -3.797761038286486e+00, -3.575179442565462e+00, -3.278793012697608e+00, -2.897061676160306e+00, -2.428167354992175e+00, -1.890214042111409e+00, -1.335022740619883e+00, -8.746175453557116e-01, -6.701763899641023e-01, -5.893691480581620e-01, -4.718349623353412e-01, -3.231710080900413e-01, -1.841394629850659e-01, -8.361468666481882e-02, -2.795282522317634e-02, -5.998601482407386e-03, -6.741774113089777e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.550685854633571e+00, -5.550640812739301e+00, -5.438587007134305e+00, -5.438492829423351e+00, -5.281502702593357e+00, -5.281304852798327e+00, -5.063890635430341e+00, -5.063472081438343e+00, -4.767353142253034e+00, -4.766458452704881e+00, -4.372694665124497e+00, -4.370752073939771e+00, -3.864905215377840e+00, -3.860585341070286e+00, -3.242517591761861e+00, -3.232549317118100e+00, -2.532280081758631e+00, -2.507938034851232e+00, -1.810385540249435e+00, -1.746203429958521e+00, -1.233421133506481e+00, -1.060260069586269e+00, -9.675008495644598e-01, -6.520266078402608e-01, -8.500689805880244e-01, -5.550613491176453e-01, -6.809114274547576e-01, -4.518140888940800e-01, -4.658217498683447e-01, -2.995509799059796e-01, -2.640396351803128e-01, -1.563926699977662e-01, -1.182890711310427e-01, -6.040827675275895e-02, -3.866131670271530e-02, -1.544180345181160e-02, -8.115968994379675e-03, -2.216961724931580e-03, -9.021359636910722e-04, -1.466713895395880e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.066268834938260e-02, 0.000000000000000e+00, -2.066302369459101e-02, -2.152325550801003e-02, -1.761050914342067e-133, -2.152400094559737e-02, -2.282259955777787e-02, -1.584945822907860e-132, -2.282430956367601e-02, -2.482627076226320e-02, 3.522101828684134e-133, -2.483037528344552e-02, -2.801079763109617e-02, -1.056630548605240e-132, -2.802131416875742e-02, -3.329521454166123e-02, -1.761050914342067e-132, -3.332481739377158e-02, -4.261891879608962e-02, -1.056630548605240e-132, -4.271435063442761e-02, -6.055018035245901e-02, -2.817681462947307e-132, -6.092419566056143e-02, -9.927882878595921e-02, 4.930942560157787e-132, -1.012153821422526e-01, -1.942396910237864e-01, 2.817681462947307e-132, -2.087807479440464e-01, -4.184632774861105e-01, -1.127072585178923e-131, -5.663114094621252e-01, -6.801072631413371e-01, 0.000000000000000e+00, -1.497440191549804e+00, -8.809916358888438e-01, -1.014365326661031e-130, -2.066322711264231e+00, -1.373089598665818e+00, -4.508290340715691e-131, -3.118606532148754e+00, -2.933868187374790e+00, 1.577901619250492e-130, -7.094775109754459e+00, -9.131494774522952e+00, -5.409948408858830e-130, -2.602839175194189e+01, -4.549785056748263e+01, -2.163979363543532e-129, -1.744565296593539e+02, -4.259188304297489e+02, 0.000000000000000e+00, -2.669832911239650e+03, -9.664944501177715e+03, 0.000000000000000e+00, -1.295280216884260e+05, -7.822329941503356e+05, -9.454570104612593e-125, -2.959302152993865e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
