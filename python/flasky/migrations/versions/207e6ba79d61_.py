"""empty message

Revision ID: 207e6ba79d61
Revises: 2fd5d2ceb21e
Create Date: 2016-05-25 01:15:22.671567

"""

# revision identifiers, used by Alembic.
revision = '207e6ba79d61'
down_revision = '2fd5d2ceb21e'

from alembic import op
import sqlalchemy as sa


def upgrade():
    ### commands auto generated by Alembic - please adjust! ###
    op.create_table('posts',
    sa.Column('id', sa.Integer(), nullable=False),
    sa.Column('body', sa.Text(), nullable=True),
    sa.Column('timestamp', sa.DateTime(), nullable=True),
    sa.Column('author_id', sa.Integer(), nullable=True),
    sa.ForeignKeyConstraint(['author_id'], ['users.id'], ),
    sa.PrimaryKeyConstraint('id')
    )
    op.create_index('ix_posts_timestamp', 'posts', ['timestamp'], unique=False)
    ### end Alembic commands ###


def downgrade():
    ### commands auto generated by Alembic - please adjust! ###
    op.drop_index('ix_posts_timestamp', 'posts')
    op.drop_table('posts')
    ### end Alembic commands ###
