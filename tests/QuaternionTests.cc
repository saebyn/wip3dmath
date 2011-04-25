#include <gtest/gtest.h>

#include "wip3dmath.h"

using namespace wip3dmath;

namespace {

class QuaternionTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    qRight = Quaternion(0.0, 90.0, 0.0);
    qRight2 = Quaternion(0.7071, 0.0, 0.0, 0.7071);
    qForward = Quaternion(0.0, 0.0, 0.0);
    qUp = Quaternion(270.0, 0.0, 0.0);
    qUp2 = Quaternion(-90.0, 0.0, 0.0);
  }
 
  Quaternion q1;
  Quaternion q2;
  Quaternion qRight; // look right
  Quaternion qRight2;
  Quaternion qForward; // look forward
  Quaternion qUp; // look up
  Quaternion qUp2; // look up
};

TEST_F(QuaternionTest, EulerConstructorWorks) {
  ASSERT_EQ(qRight, qRight2);
}

TEST_F(QuaternionTest, EqualityWorks) {
  ASSERT_TRUE( qRight == qRight );
  ASSERT_TRUE( q1 == q2 );
  ASSERT_FALSE( qRight == qForward );
  ASSERT_FALSE( qUp == q1 );
}

TEST_F(QuaternionTest, InequalityWorks) {
  ASSERT_FALSE( qRight != qRight );
  ASSERT_FALSE( q1 != q2 );
  ASSERT_TRUE( qRight != qForward );
  ASSERT_TRUE( qUp != q1 );
}

TEST_F(QuaternionTest, SetWorks) {
  q1.set(0.0, 90.0, 0.0);
  ASSERT_EQ(qRight, q1);
  ASSERT_NE(qUp, q1);
}

TEST_F(QuaternionTest, SetQWorks) {
  q1.set(qRight);
  ASSERT_EQ(qRight, q1);
}

TEST_F(QuaternionTest, GetWorks) {
  qForward.get(q1);
  ASSERT_EQ(qForward, q1);
}

TEST_F(QuaternionTest, MultiplicationWorks) {
  ASSERT_EQ(qRight, qForward * qRight);

  q1.set(270.0, 90.0, 0.0);

  ASSERT_EQ(q1, qRight * qUp);
}

TEST_F(QuaternionTest, GetMatrixWorks) {
  // q1.get_matrix() -> Matrix 
}

} // namespace
