#include <gui/containers/Boss.hpp>
#include <BitmapDatabase.hpp>


Boss::Boss()
	:Enemy(OOB) {
	Application::getInstance()->registerTimerWidget(this);
}

void Boss::initialize()
{
    BossBase::initialize();
}

void Boss::handleTickEvent() {
	tickCounter++;
	MoveAnimator<BossBase>::handleTickEvent();

	switch(state) {
	case ENTER:
		if (tickCounter == 1) {
			//move to outside screen
			moveTo(startX, startY);
			//move to standing position
			startMoveAnimation(endX, endY, 100);
		}
		else if (tickCounter == 124) {
			startMoveAnimation(0, getY(), 126);
		}
		else if (tickCounter % 250 == 0) {
			startMoveAnimation((tickCounter % 500 == 250) ? 125 : 0, getY(), 250);
		}
		else if (tickCounter > 250 && tickCounter % 125 == 0)
			emitFireBullet1TriggerCallback();
		else if (tickCounter % 300 == 0) {
			emitFireBullet0TriggerCallback();
		}

		break;
	case DEAD:
		if (tickCounter == 1) {
			animatedImage.setBitmaps(BITMAP_EXPLOSION0_ID, BITMAP_EXPLOSION7_ID);
			animatedImage.setUpdateTicksInterval(5);
			animatedImage.startAnimation(false, true, false);
			cancelMoveAnimation();
		}
		else if (tickCounter == 40)
			reset();
		break;
	default: break;
	}
}

const Rect& Boss::getHitBox() {
	return getRect();
}

void Boss::reset() {
	state = OOB;
	animatedImage.setBitmaps(BITMAP_ENEMY0_ID, BITMAP_ENEMY0_ID);
	moveTo(startX, startY);
}
