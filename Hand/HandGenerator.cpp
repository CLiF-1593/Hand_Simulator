#include "HandGenerator.h"

Hand* HandGenerator::Generate() {
	double HL, HB;
	HL = 500;
	HB = 375;
	
	Hand* hand = new Hand();
	// Base
	auto* base = (new Joint<JointType::TIRTARY>(0))->InitAngle(0, 0, 0);

	// Carpals
	auto thumb_carpal = (new Joint<JointType::NONE>(0.25 * HL, base))->InitAngle(0, 40, 40);
	auto index_carpal = (new Joint<JointType::NONE>(0.25 * HL, base))->InitAngle(0, 0, 60);
	auto middle_carpal = (new Joint<JointType::NONE>(0.25 * HL, base))->InitAngle(0, 0, 80);
	auto ring_carpal = (new Joint<JointType::NONE>(0.25 * HL, base))->InitAngle(0, 0, 100);
	auto pinky_carpal = (new Joint<JointType::NONE>(0.25 * HL, base))->InitAngle(0, 0, 120);

	// Metacarpas : Carpometacarpal (CMC)
	auto thumb_metacarpa = (Joint<JointType::TIRTARY>*)(new Joint<JointType::TIRTARY>(0.251 * HL, thumb_carpal))->InitAngle(0, 0, 0)->SetRangeX(0, 80)->SetRangeY(0, 50)->SetRangeZ(0, 50);
	auto index_metacarpa = (new Joint<>(sqrt(pow(0.374 * HL, 2) + pow(0.126 * HB, 2)), index_carpal))->InitAngle(0, 0, 15);
	auto middle_metacarpa = (new Joint<>(0.373 * HL, middle_carpal))->InitAngle(0, 0, 5);
	auto ring_metacarpa = (Joint<JointType::SECONDARY>*)(new Joint<JointType::SECONDARY>(sqrt(pow(0.336 * HL, 2) + pow(0.077 * HB, 2)), ring_carpal))->InitAngle(0, 0, -5)->SetRangeX(0, 10)->SetRangeZ(-5, 0);
	auto pinky_metacarpa = (Joint<JointType::SECONDARY>*)(new Joint<JointType::SECONDARY>(sqrt(pow(0.295 * HL, 2) + pow(0.179 * HB, 2)), pinky_carpal))->InitAngle(0, 0, -15)->SetRangeX(0, 20)->SetRangeZ(-13, 0);

	// Phalanges : Metacarpophalangeal (MCP)
	auto thumb_phalange_first = (Joint<JointType::SECONDARY>*)(new Joint<JointType::SECONDARY>(0.196 * HL, thumb_metacarpa))->InitAngle(0, 0, 0)->SetRangeX(0, 90);
	auto index_phalange_first = (Joint<JointType::SECONDARY>*)(new Joint<JointType::SECONDARY>(0.265 * HL, index_metacarpa))->InitAngle(0, 0, 0)->SetRangeX(-30, 90)->SetRangeZ(-30, 30);
	auto middle_phalange_first = (Joint<JointType::SECONDARY>*)(new Joint<JointType::SECONDARY>(0.277 * HL, middle_metacarpa))->InitAngle(0, 0, 0)->SetRangeX(-10, 90)->SetRangeZ(-30, 30);
	auto ring_phalange_first = (Joint<JointType::SECONDARY>*)(new Joint<JointType::SECONDARY>(0.259 * HL, ring_metacarpa))->InitAngle(0, 0, 0)->SetRangeX(-10, 90)->SetRangeZ(-30, 30);
	auto pinky_phalange_first = (Joint<JointType::SECONDARY>*)(new Joint<JointType::SECONDARY>(0.206 * HL, pinky_metacarpa))->InitAngle(0, 0, 0)->SetRangeX(-30, 90)->SetRangeZ(-30, 30);

	// Phalanges : Proximal Interphalangeal (PIP)
	auto index_phalange_second = (Joint<JointType::PRIMARY>*)(new Joint<JointType::PRIMARY>(0.143 * HL, index_phalange_first))->InitAngle(0, 0, 0)->SetRangeX(-2, 110);
	auto middle_phalange_second = (Joint<JointType::PRIMARY>*)(new Joint<JointType::PRIMARY>(0.170 * HL, middle_phalange_first))->InitAngle(0, 0, 0)->SetRangeX(-2, 110);
	auto ring_phalange_second = (Joint<JointType::PRIMARY>*)(new Joint<JointType::PRIMARY>(0.165 * HL, ring_phalange_first))->InitAngle(0, 0, 0)->SetRangeX(-2, 110);
	auto pinky_phalange_second = (Joint<JointType::PRIMARY>*)(new Joint<JointType::PRIMARY>(0.117 * HL, pinky_phalange_first))->InitAngle(0, 0, 0)->SetRangeX(-2, 110);

	// Phalanges : Distal Interphalangeal (DIP)
	auto thumb_phalange_third = (Joint<JointType::PRIMARY>*)(new Joint<JointType::PRIMARY>(0.158 * HL, thumb_phalange_first))->InitAngle(0, 0, 0)->SetFlag(JointFlag::END_EFFECTOR)->SetRangeX(-10, 90);
	auto index_phalange_third = (Joint<JointType::PRIMARY>*)(new Joint<JointType::PRIMARY>(0.097 * HL, index_phalange_second))->InitAngle(0, 0, 0)->SetFlag(JointFlag::END_EFFECTOR)->SetRangeX(-5, 80);
	auto middle_phalange_third = (Joint<JointType::PRIMARY>*)(new Joint<JointType::PRIMARY>(0.108 * HL, middle_phalange_second))->InitAngle(0, 0, 0)->SetFlag(JointFlag::END_EFFECTOR)->SetRangeX(-5, 80);
	auto ring_phalange_third = (Joint<JointType::PRIMARY>*)(new Joint<JointType::PRIMARY>(0.107 * HL, ring_phalange_second))->InitAngle(0, 0, 0)->SetFlag(JointFlag::END_EFFECTOR)->SetRangeX(-5, 80);
	auto pinky_phalange_third = (Joint<JointType::PRIMARY>*)(new Joint<JointType::PRIMARY>(0.093 * HL, pinky_phalange_second))->InitAngle(0, 0, 0)->SetFlag(JointFlag::END_EFFECTOR)->SetRangeX(-5, 80);

	// Wrist Flesh
	auto wrist_flesh_1 = (new Joint<JointType::NONE>(0.125 * HL, base))->InitAngle(0, 0, 0)->SetFlag(JointFlag::VIRTUAL_JOINT);
	auto wrist_flesh_2 = (new Joint<JointType::NONE>(0.125 * HL, base))->InitAngle(0, 0, 180)->SetFlag(JointFlag::VIRTUAL_JOINT);

	hand->AddJoint(base);
	hand->AddJoint(wrist_flesh_1);
	hand->AddJoint(thumb_carpal)->AddJoint(thumb_metacarpa)->AddJoint(thumb_phalange_first)->AddJoint(thumb_phalange_third);
	hand->AddJoint(index_carpal)->AddJoint(index_metacarpa)->AddJoint(index_phalange_first)->AddJoint(index_phalange_second)->AddJoint(index_phalange_third);
	hand->AddJoint(middle_carpal)->AddJoint(middle_metacarpa)->AddJoint(middle_phalange_first)->AddJoint(middle_phalange_second)->AddJoint(middle_phalange_third);
	hand->AddJoint(ring_carpal)->AddJoint(ring_metacarpa)->AddJoint(ring_phalange_first)->AddJoint(ring_phalange_second)->AddJoint(ring_phalange_third);
	hand->AddJoint(pinky_carpal)->AddJoint(pinky_metacarpa)->AddJoint(pinky_phalange_first)->AddJoint(pinky_phalange_second)->AddJoint(pinky_phalange_third);
	hand->AddJoint(wrist_flesh_2);

	hand->clicking_motion_function_set.push_back(new function<void()>([=]() {
			static Progress progress;
			thumb_metacarpa->SetAngleAsProgress(progress(), progress(), 0.0);
			thumb_phalange_first->SetAngleAsProgress(progress(), 0);
			thumb_phalange_third->SetAngleAsProgress(0.1 + progress() * 0.5);
			++progress;
		})
	);
	hand->clicking_motion_function_set.push_back(new function<void()>([=]() {
			static Progress progress;
			index_phalange_first->SetAngleAsProgress(progress(), 0.5);
			index_phalange_second->SetAngleAsProgress(progress());
			index_phalange_third->SetAngleAsProgress(progress());
			++progress;
		})
	);
	hand->clicking_motion_function_set.push_back(new function<void()>([=]() {
			static Progress progress;
			middle_phalange_first->SetAngleAsProgress(progress(), 0.5);
			middle_phalange_second->SetAngleAsProgress(progress());
			middle_phalange_third->SetAngleAsProgress(progress());
			++progress;
		})
	);
	hand->clicking_motion_function_set.push_back(new function<void()>([=]() {
			static Progress progress;
			ring_metacarpa->SetAngleAsProgress(progress(), 1.0);
			ring_phalange_first->SetAngleAsProgress(progress(), 0.5);
			ring_phalange_second->SetAngleAsProgress(progress());
			ring_phalange_third->SetAngleAsProgress(progress());
			++progress;
		})
	);
	hand->clicking_motion_function_set.push_back(new function<void()>([=]() {
			static Progress progress;
			pinky_metacarpa->SetAngleAsProgress(progress(), 1.0);
			pinky_phalange_first->SetAngleAsProgress(progress(), 0.5);
			pinky_phalange_second->SetAngleAsProgress(progress());
			pinky_phalange_third->SetAngleAsProgress(progress());
			++progress;
		})
	);
	return hand;
}
